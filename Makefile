# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -O2

# Define the target executable name
TARGET = assignment

# Define the source files
SRC = assignment.c

# Rule to build the target executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(SRC:.c=.o)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC:.c=.o)

# Rule to build and run tests
test: $(TARGET) test_program
	./$(TARGET) 5 10
	./test_program

# Rule to compile the test program
test_program: test.c
	$(CC) $(CFLAGS) -o test_program test.c

# Rule to clean up the build files
clean:
	rm -f $(TARGET) test_program $(SRC:.c=.o)