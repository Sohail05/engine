

#include <SFML/Graphics.hpp>

#include "pathfinder\PathFinder.h"

using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

#include "cEngine.h"

/**
* the program entry point
* @param argc the argument count
* @param argv the array containing the arguments
*/

int main(int argc, char** argv) {

	cEngine *Engine = new cEngine( TITLE, WIDTH, HEIGHT, 0, 0 );

	RenderWindow window(VideoMode( Engine->GetWindowWidth(), Engine->GetWindowHeight() ), Engine->GetWindowTitle());
	window.setPosition( sf::Vector2i( Engine->GetWindowPositionX(), Engine->GetWindowPositionY() ) );

	/*
	int32_t map[5][6] = {
		{ 1, 3, 3, 0, 3, 2 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 0, 3, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 }
	};

	mapdata mapdata;
	mapdata.map = (int32_t**)map;
	mapdata.width = 6;
	mapdata.height = 5;

	auto searchdata = PathFinder::search(mapdata, true);
	if (searchdata->isPathFound()) {
		auto path = searchdata->getPath();
		for (auto node : *path) {
			printf("%i %i\n", node->getX(), node->getY());
		}
	}
	searchdata->release(); // or delete searchdata; // or PathFinder::release(searchdata);
	*/

	Engine->Initialize();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color::Red);

		Engine->Render( &window );

		//window.draw();
		window.display();
	}

    return EXIT_SUCCESS;
}