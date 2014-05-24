#ifndef _KERNEL_INTERRUPT_HPP
#define _KERNEL_INTERRUPT_HPP
#include "std.hpp"

#define GATE_PRESENT 0x80
#define GATE_NOT_PRESENT 0x00
#define GATE_DPL0 0x00
#define GATE_DPL1 0x20
#define GATE_DPL2 0x40
#define GATE_DPL3 0x60
#define GATE_MAGIC 0x0E
#define GATE_INTERRUPT 0x00
#define GATE_TRAP 0x01

namespace Interrupt {
	typedef struct {
		uint16_t offset_low;
		uint16_t segment;
		uint8_t zero;
		uint8_t flags;
		uint16_t offset_high;
	} __attribute__((packed)) InterruptGate;

	// TrapGate has the same structure as an InterruptGate
	// only the `flags` constant is different
	typedef InterruptGate TrapGate;

	typedef struct {
		uint16_t limit;
		uint32_t pointer;
	} __attribute__((packed)) IDTR;

	extern InterruptGate idt[];
	extern IDTR idtr;

	void initialize();
	void set_interrupt(int interrupt, void (*handler)(void), uint8_t flags);
}
#endif