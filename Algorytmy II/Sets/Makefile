CFLAGS	:= -Wall -std=c++20 -pedantic
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean
all: setSimple.x setLinked.x dictionarySimple.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

setSimple.x: setSimple.o
setSimple.o: setSimple.cpp Sets.h

setLinked.x: setLinked.o
setLinked.o: setLinked.cpp Sets.h

dictionarySimple.x: dictionarySimple.o
dictionarySimple.o: dictionarySimple.cpp Sets.h

clean:
	$(RM) *.[ox]