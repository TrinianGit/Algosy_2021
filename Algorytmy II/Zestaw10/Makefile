CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: AllCitiesConnected.x BetweenTwo.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

AllCitiesConnected.x: AllCitiesConnected.o
AllCitiesConnected.o: AllCitiesConnected.cpp Graph.hpp

BetweenTwo.x: BetweenTwo.o
BetweenTwo.o: BetweenTwo.cpp Graph.hpp

clean:
	$(RM) *.[ox]