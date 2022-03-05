CFLAGS	:= -Wall -std=c++11 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: BubbleSort.x SelectionSort.x InsertionSort.x CountingSort.x SelectionMinmax.x Generator.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

BubbleSort.x: BubbleSort.o
BubbleSort.o: BubbleSort.cpp
SelectionSort.x: SelectionSort.o
SelectionSort.o: SelectionSort.cpp
InsertionSort.x: InsertionSort.o
InsertionSort.o: InsertionSort.cpp
CountingSort.x: CountingSort.o
CountingSort.o: CountingSort.cpp
SelectionMinmax.x: SelectionMinmax.o
SelectionMinmax.o: SelectionMinmax.cpp
Generator.x: Generator.o
Generator.o: Generator.cpp

clean:
	$(RM) *.[ox]