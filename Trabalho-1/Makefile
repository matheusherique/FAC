TARGET = main
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

all: $(TARGET)
main: $(TARGET).o
	gcc -o $(TARGET) $(TARGET).o $(LIBS)
main.o: $(TARGET).c  # program.h headers.h
	gcc -c $(TARGET).c $(LIBS)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
