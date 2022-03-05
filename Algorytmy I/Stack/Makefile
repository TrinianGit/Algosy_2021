CC		:= g++
CFLAGS	:= -Wall -std=c++11 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: Stack.x Generator.x ONP.x

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

Stack.x: Stack.o
Stack.o: Stack.cpp 
Generator.x: Generator.o
Generator.o: Generator.cpp
ONP.x: ONP.o
ONP.o: ONP.cpp

clean:
	$(RM) *.[ox]