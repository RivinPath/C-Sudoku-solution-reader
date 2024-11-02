# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pthread

# Source files
SOURCES = main.c validation.c threads.c
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = mssv

# Default target
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Compilation rule
%.o: %.c shared.h validation.h threads.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)