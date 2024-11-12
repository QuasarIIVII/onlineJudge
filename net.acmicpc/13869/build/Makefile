# Makefile

# Target executable name
TARGET = a

# Source and object files
ASM_SOURCE = a.asm
OBJECT = a.o

# Compiler and assembler
CC = gcc
ASM = nasm

# Flags for assembler and compiler
ASMFLAGS = -f elf64 -g -F dwarf
CFLAGS = -no-pie -g

# Default target
all: $(TARGET)

# Link object file to create final executable
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET)

# Assemble the ASM source file
$(OBJECT): $(ASM_SOURCE)
	$(ASM) $(ASMFLAGS) $(ASM_SOURCE) -o $(OBJECT)

# Clean target
clean:
	rm -f $(OBJECT) $(TARGET)

# Phony targets
.PHONY: all clean

