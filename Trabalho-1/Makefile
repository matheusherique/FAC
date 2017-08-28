TARGET = main
HEADERS = geometric_types
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

all: $(TARGET)
main: $(TARGET).o
	gcc -o $(TARGET) $(TARGET).o $(LIBS) $(HEADERS).h
main.o: $(TARGET).c $(HEADERS).h
	gcc -c $(TARGET).c $(HEADERS).h $(LIBS)

clean:
	-rm -f *.o *.gch
	-rm -f $(TARGET)
