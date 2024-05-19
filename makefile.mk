CC = gcc
CFLAGS = -Wall
TARGET = grade_card_program

all: $(TARGET)

$(TARGET): main.o student.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o student.o

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f *.o $(TARGET)
