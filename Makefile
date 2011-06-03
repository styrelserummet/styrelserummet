SDL_CFLAGS=`sdl-config --cflags`
SDL_LFLAGS=`sdl-config --libs` -lSDL_image

CFLAGS=$(SDL_CFLAGS)
LFLAGS=$(SDL_LFLAGS)
CC=g++ -g

all: spritedemo

spritedemo: sprite.o spritedemo.o
	$(CC) $(LFLAGS) sprite.o spritedemo.o -o spritedemo

spritedemo.o: spritedemo.cpp spritedemo.h
	$(CC) $(CFLAGS) -c spritedemo.cpp -o spritedemo.o

sprite.o: sprite.cpp sprite.h
	$(CC) $(CFLAGS) -c sprite.cpp -o sprite.o

styrelserummet: styrelserummet.cpp
	g++ styrelserummet.cpp -o styrelserummet `sdl-config --cflags --libs` -lSDL_image

clean:
	touch a.o
	rm -f styrelserummet *.o spritedemo

