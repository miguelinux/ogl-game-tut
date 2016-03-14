SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGETS=$(basename $(SOURCES))

CPPFLAGS= -Wall -Wextra

LDLIBS= -lglfw


.PHONY: all
all: $(TARGETS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

primero: primero.o
	$(LINK.cpp) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS) $(OBJECTS)


