CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = app

OBJ = main.o math_utils.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c math_utils.h
	$(CC) $(CFLAGS) -c main.c -o main.o

math_utils.o: math_utils.c math_utils.h
	$(CC) $(CFLAGS) -c math_utils.c -o math_utils.o

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
