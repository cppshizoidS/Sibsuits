CC = clang
CFLAGS = -Wall -Wextra 
LDFLAGS = -lncurses -lrt

SRCS = main.c
OBJS = $(SRCS:.c=.o)
TARGET = gameoflife

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
