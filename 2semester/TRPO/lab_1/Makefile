CC = clang

CFLAGS = -Wall -Wextra -std=c11

SRC = main.c

TARGET = lab1

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f ${TARGET}
