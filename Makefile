CC=g++
CFLAGS=-c -Wall `sdl-config --cflags`
LDFLAGS=`sdl-config --libs` -lSDL_image

SOURCES=spritedemo.cpp sprite.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=spritedemo

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	touch a.o $(EXECUTABLE)
	rm -f *.o $(EXECUTABLE)
