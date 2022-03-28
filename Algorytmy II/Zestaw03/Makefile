CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: QueueTester.x priorityQueue.x priorityQueueBinary.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

QueueTester.x: QueueTester.o
QueueTester.o: QueueTester.cpp priorityQueues.hpp

priorityQueue.x: priorityQueue.o
priorityQueue.o: priorityQueue.cpp priorityQueues.hpp

priorityQueueBinary.x: priorityQueueBinary.o
priorityQueueBinary.o: priorityQueueBinary.cpp priorityQueues.hpp

clean:
	$(RM) *.[ox]