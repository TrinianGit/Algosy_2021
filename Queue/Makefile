CC		:= g++
CFLAGS	:= -Wall -std=c++11 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: Queue.x Generator.x Radix.x

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

Queue.x: Queue.o
Queue.o: Queue.cpp 
Generator.x: Generator.o
Generator.o: Generator.cpp
Radix.x: Radix.o
Radix.o: Radix.cpp

clean:
	$(RM) *.[ox]