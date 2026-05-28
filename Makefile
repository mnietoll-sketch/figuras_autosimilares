CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

all: testLine

testLine: turtlec.c examples/testLine.c turtlec.h draw.h draw.c
	$(CC) $(CFLAGS) examples/testLine.c draw.c turtlec.c -g -o testLine $(LDLIBS)

clear:
	rm -f testLine
