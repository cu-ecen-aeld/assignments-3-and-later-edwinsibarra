# Makefile for the "writer" application

# Compiler and flags
CC := gcc
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
    CC := $(CROSS_COMPILE)$(CC)
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
