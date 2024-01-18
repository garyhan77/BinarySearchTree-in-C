CC = gcc
CFLAGS = -Wall -std=c99 -O2
TARGET = mymatrix

OBJS = main.o matrix.o bstree.o datatype.o

.PHONY: clean

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h bstree.h datatype.h
	$(CC) $(CFLAGS) -c matrix.c

bstree.o: bstree.c bstree.h datatype.h
	$(CC) $(CFLAGS) -c bstree.c

datatype.o: datatype.c datatype.h
	$(CC) $(CFLAGS) -c datatype.c

clean:
	rm -f $(TARGET) $(OBJS)
