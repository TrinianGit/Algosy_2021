CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: CheckGraphs.x CheckCoherence.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

CheckGraphs.x: CheckGraphs.o
CheckGraphs.o: CheckGraphs.cpp Graph.hpp

CheckCoherence.x: CheckCoherence.o
CheckCoherence.o: CheckCoherence.cpp Graph.hpp

clean:
	$(RM) *.[ox]