styrelserummet: styrelserummet.cpp
	g++ styrelserummet.cpp -o styrelserummet `sdl-config --cflags --libs` -lSDL_image

clean:
	rm -f styrelserummet

