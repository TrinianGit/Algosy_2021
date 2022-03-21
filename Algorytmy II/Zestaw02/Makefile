CPPFLAGS	:= -g -Wall -std=c++17 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: setHashed.x setSimple.x SetTester.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CPPLAGS) -c -o $@ $<

setHashed.x: setHashed.o
setHashed.o: setHashed.cpp Sets.hpp

setSimple.x: setSimple.o
setSimple.o: setSimple.cpp Sets.hpp

SetTester.x: SetTester.o
SetTester.o: SetTester.cpp Sets.hpp

clean:
	$(RM) *.[ox]