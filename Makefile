CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = hotel_system
SRC = std.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) hotel.txt *.o
