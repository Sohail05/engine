

#include <SFML/Graphics.hpp>

<<<<<<< HEAD
#include "pathfinder\PathFinder.h"

=======
>>>>>>> origin/master
using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

/**
* the program entry point
* @param argc the argument count
* @param argv the array containing the arguments
*/
<<<<<<< HEAD

=======
>>>>>>> origin/master
int main(int argc, char** argv) {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);

	int map[5][6] = {
		{ 1, 3, 3, 0, 3, 2 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 0, 3, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 }
	};

	mapdata mapdata;
	mapdata.map = (int**)map;
	mapdata.width = 6;
	mapdata.height = 5;

	auto searchdata = PathFinder::search(mapdata, true);
	if (searchdata->isPathFound()) {
		auto path = searchdata->getPath();
		for (auto node : *path) {
			printf("%i %i\n", node->getX(), node->getY());
		}
	}

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color::Red);
		//window.draw();
		window.display();
	}

    return EXIT_SUCCESS;
}