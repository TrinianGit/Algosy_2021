CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: setSimple.x setLinked.x dictionarySimple.x SetTester.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

setSimple.x: setSimple.o
setSimple.o: setSimple.cpp Sets.hpp

setLinked.x: setLinked.o
setLinked.o: setLinked.cpp Sets.hpp LinkedList.hpp

dictionarySimple.x: dictionarySimple.o
dictionarySimple.o: dictionarySimple.cpp Sets.hpp

SetTester.x: SetTester.o
SetTester.o: SetTester.cpp Sets.hpp

clean:
	$(RM) *.[ox]