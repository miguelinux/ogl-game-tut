SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=mijuego

CPPFLAGS= -Wall -Wextra
CFLAGS= -I/usr/include/libdrm

LDLIBS= -lglfw -lGL


.PHONY: all
all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)


