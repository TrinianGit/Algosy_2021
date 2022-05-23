CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: Prim.x Kruskal.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

Prim.x: Prim.o
Prim.o: Prim.cpp Graph.hpp

Kruskal.x: Kruskal.o
Kruskal.o: Kruskal.cpp Graph.hpp
clean:
	$(RM) *.[ox]