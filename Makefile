# Compiler and flags
# The compiler will look for header fiels in 'include/' and 'include/tensor' directory. 
CC = gcc
CFLAGS = -Iinclude -Iinclude/tensor -Wall -Wextra -g -Wno-missing-braces

# Find all .c files in src and its subdirectories
# Replace .c with .o for object files
SRC = $(wildcard src/*.c src/**/*.c)	
OBJ = $(SRC:.c=.o)						

# Final executable name
EXEC = NumC

# Default target for building the executable
# Usage: `make`
all: $(EXEC)

# Linking the executable (target: prerequisite)
# $(EXEC) is dependent on all object files in $(OBJ)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Compile each .c file to an .o file
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean up command to remove object files and executable file
# Usage: `make clean`
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets to indicate 'all' and 'clean' are not files
.PHONY: all clean



# Notes to self:
# `%` 			in pattern rules matches any set of characters
# `*` 			matches all files in a given directory
# `**` 			in wildcard function matches files/directories recursively
# `-Wall` 		(Warnings All) enables most compiler warnings
# `-Wextra` 	(Warnings Extra) enables additional compiler warnings for other common oversights 