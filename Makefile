SDL_CFLAGS=`sdl-config --cflags`
SDL_LFLAGS=`sdl-config --libs` -lSDL_image

CFLAGS=$(SDL_CFLAGS)
LFLAGS=$(SDL_LFLAGS)
CC=g++ -g

spritedemo: sprite.o main.o
	$(CC) $(LFLAGS) sprite.o main.o -o spritedemo

main.o: main.cpp Main.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

sprite.o: Sprite.cpp Sprite.h
	$(CC) $(CFLAGS) -c Sprite.cpp -o sprite.o

styrelserummet: styrelserummet.cpp
	g++ styrelserummet.cpp -o styrelserummet `sdl-config --cflags --libs` -lSDL_image

clean:
	touch a.o
	rm -f styrelserummet *.o spritedemo

