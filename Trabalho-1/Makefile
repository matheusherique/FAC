TARGET = main
TARGETS = io.c operation.c
OBJECTS = io.o operation.o main.o
HEADERS = geometric_types.h io.h operation.h
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -o $(TARGET) $(LIBS)

$(TARGET).o: $(TARGET).c $(HEADERS)
	gcc -o main.o -c main.c $(LIBS)

io.o: io.c
	gcc -o io.o -c io.c $(LIBS)

operation.o: operation.c
	gcc -o operation.o -c operation.c $(LIBS)

clean:
	-rm -f *.o *.gch
	-rm -f $(TARGET)
