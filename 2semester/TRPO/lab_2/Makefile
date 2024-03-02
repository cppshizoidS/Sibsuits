CC = clang
CFLAGS = -Wall -Wextra -O3
SRC = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
TARGET = lab2

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) -lm

clean:
	rm -f $(TARGET)
