CC		:= g++
CFLAGS	:= -Wall -std=c++11 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: LinkedList.x ArrayList.x CursorList.x

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

LinkedList.x: LinkedList.o
LinkedList.o: LinkedList.cpp LinkedList.hpp
ArrayList.x: ArrayList.o
ArrayList.o: ArrayList.cpp ArrayList.hpp
CursorList.x: CursorList.o
CursorList.o: CursorList.cpp CursorList.hpp
#Generator.x: Generator.o
#Generator.o: Generator.cpp

clean:
	$(RM) *.[ox]