CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: DictionaryGame.x Pancakes.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

DictionaryGame.x: DictionaryGame.o
DictionaryGame.o: DictionaryGame.cpp Graph.hpp

Pancakes.x: Pancakes.o
Pancakes.o: Pancakes.cpp Graph.hpp

clean:
	$(RM) *.[ox]