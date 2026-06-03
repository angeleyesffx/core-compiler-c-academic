# Final compiler executable name
TARGET = compiler

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Automatically locate all .c source files in the directory
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Default rule (compiles the entire project)
all: $(TARGET)

# Link object files to create the final compiler binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated binary and object files
clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
