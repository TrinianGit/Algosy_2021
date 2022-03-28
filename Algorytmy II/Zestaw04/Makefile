CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: GraphTester.x Graph.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

GraphTester.x: GraphTester.o
GraphTester.o: GraphTester.cpp Graph.hpp

Graph.x: Graph.o
Graph.o: Graph.cpp Graph.hpp

clean:
	$(RM) *.[ox]