CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra -Wpedantic -std=c11 -Iinclude
TARGET=minidb
SRC=src/main.c src/storage.c
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)
clean:
	rm -f $(TARGET) minidb.dat
.PHONY: all clean
