CC		:= g++
CFLAGS	:= -Wall -std=c++11 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: LinkedList.x

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

LinkedList.x: LinkedList.o
LinkedList.o: LinkedList.cpp LinkedList.hpp
#Generator.x: Generator.o
#Generator.o: Generator.cpp
#Radix.x: Radix.o
#Radix.o: Radix.cpp ArrayQueue.hpp

clean:
	$(RM) *.[ox]