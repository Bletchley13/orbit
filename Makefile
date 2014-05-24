SRC_DIRS := src/ src/kernel/

# Find all files in the SRC_DIRS directories suffixed by .cpp
CXX_SRC := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)*.cpp))
# Append .o to every file. Don't replace extension, could cause name conflicts.
CXX_OBJ := $(foreach file, $(CXX_SRC), $(file)o)

# Same here, different extension.
ASM_SRC := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)*.asm))
ASM_OBJ := $(foreach file, $(ASM_SRC), $(file)o)

INCLUDE_DIRS := 

# Assembler
AS := nasm
AS_FLAGS = -felf

CXX := /home/campbell/opt/cross/bin/i586-elf-g++
CXX_FLAGS := $(foreach dir, $(INCLUDE_DIRS), -I$(dir)) -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -std=c++11

LD := $(CXX)
LD_FLAGS := -ffreestanding -O2 -nostdlib -lgcc

SOURCES := $(CXX_SRC) $(ASM_SRC)
OBJECTS := $(CXX_OBJ) $(ASM_OBJ)

# NO suffixed slash
ISO_DIR := iso
ISO := orbit.iso
BIN := iso/boot/orbit.bin

VM := qemu-system-x86_64
VM_FLAGS := -cdrom $(ISO) -net none

.PHONY: all build run clean

all: $(ISO) run

build: $(ISO)

run:
	$(VM) $(VM_FLAGS)

$(ISO): $(BIN) $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)

$(BIN): $(OBJECTS) Makefile
	$(LD) $(OBJECTS) -T src/linker.ld -o $(BIN) $(LD_FLAGS)

%.cppo: %.cpp Makefile
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

%.asmo: %.asm Makefile
	$(AS) $< -o $@ $(AS_FLAGS)

clean:
	rm -f $(CXX_OBJ) $(ASM_OBJ) $(ISO) $(BIN)