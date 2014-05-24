#include "interrupt.hpp"
#include "std.hpp"
#include "terminal.hpp"

extern "C" void interrupt_null();

extern "C" void interrupt_handle() {
	Terminal::puts("Interrupt!");
}

namespace Interrupt {
	InterruptGate idt[256];
	IDTR idtr;

	void initialize() {
		idtr.limit = sizeof(InterruptGate) * 256 - 1;
		idtr.pointer = (uint32_t) &idt;

		for (size_t i = 0; i < 256; ++i) {
			set_interrupt(i, interrupt_null, GATE_PRESENT + GATE_INTERRUPT + GATE_DPL0);
		}

		asm volatile("lidt (%0)" : : "r"(&idtr));
		asm volatile("sti");
	}

	void set_interrupt(int interrupt, void (*handler)(void), uint8_t flags) {
		uint32_t handler_offset = (uint32_t) handler;

		uint16_t segment = 0x08;
		asm volatile("movw %%cs, %0" : "=g"(segment));

		idt[interrupt].offset_low = handler_offset & 0xFFFF;
		idt[interrupt].segment = segment;
		idt[interrupt].zero = 0;
		idt[interrupt].flags = flags;
		idt[interrupt].offset_high = (handler_offset >> 16) & 0xFFFF;
	}
}