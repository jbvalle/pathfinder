CC = gcc

CFLAGS = -g -Wall -Wextra -pedantic -O0

SRCS = $(wildcard *.c)

TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -lm
