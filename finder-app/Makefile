# Makefile for the "writer" application

# Compiler and flags
CROSS_COMPILE ?= ~/aarm/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra

# Output directory
OUTDIR := bin

# Default target: build the "writer" application
.DEFAULT_GOAL := writer

# Platform-specific settings
ifeq ($(CROSS_COMPILE),)
    # Native build
    TARGET := $(OUTDIR)/writer
else
    # Cross-compilation
    TARGET := $(OUTDIR)/writer-cross
endif

# Source files
SRCS := writer.c

# Object files
OBJS := $(SRCS:%.c=$(OUTDIR)/%.o)

# Build the application
$(TARGET): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target: remove application and object files
clean:
	rm -rf $(OUTDIR)

# Compile source files
$(OUTDIR)/%.o: %.c
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
