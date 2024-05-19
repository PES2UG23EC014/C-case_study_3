CC= gcc
CFLAGS= -Wall -Wextra

EXECUTABLE= gradecard

all: $(EXECUTABLE)

$(EXECUTABLE): main.o grades.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) main.o grades.o

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

grades.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f $(EXECUTABLE) main.o grades.o
