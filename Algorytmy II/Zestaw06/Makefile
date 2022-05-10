CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: GraphTester.x CrossRoads.x Chess.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

GraphTester.x: GraphTester.o
GraphTester.o: GraphTester.cpp Graph.hpp

CrossRoads.x: CrossRoads.o
CrossRoads.o: CrossRoads.cpp Graph.hpp

Chess.x: Chess.o
Chess.o: Chess.cpp Graph.hpp

clean:
	$(RM) *.[ox]