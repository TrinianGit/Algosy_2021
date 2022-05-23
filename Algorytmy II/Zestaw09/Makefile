CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: Dijkstra.x ShortestPath.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

Dijkstra.x: Dijkstra.o
Dijkstra.o: Dijkstra.cpp Graph.hpp

ShortestPath.x: ShortestPath.o
ShortestPath.o: ShortestPath.cpp Graph.hpp

clean:
	$(RM) *.[ox]