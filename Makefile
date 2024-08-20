# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = crypto_stats
SOURCES = crypto_stats.c
HEADERS = crypto_stats.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
    $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
    rm -f $(TARGET)
