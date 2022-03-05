CFLAGS    := -Wall -std=c++11 -pedantic
LDFLAGS    :=
LDLIBS    :=

.PHONY: all clean
all: Dict.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

Dict.x: Dict.o
Dict.o: Dict.cpp Dict.hpp LinkedList.hpp
clean:
	$(RM) *.[ox]
