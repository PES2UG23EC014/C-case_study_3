CC = gcc
CFLAGS = -Wall -Wextra -I.

SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)
HEADER = student.h
EXECUTABLE = grade_card_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	del $(EXECUTABLE) $(OBJS)
