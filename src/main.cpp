

#include <SFML/Graphics.hpp>

#include "pathfinder\PathFinder.h"

using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

#include "Engine.h"

#ifdef _DEBUG
#include <vld.h>
#endif

/**
* The program entry point
* @param argc the argument count
* @param argv the array containing the arguments
* @return the returncode of the program
*/
int main(int argc, char** argv) {

	Engine *m_Engine = new Engine( TITLE, WIDTH, HEIGHT, 0, 0 );

	RenderWindow window(VideoMode( m_Engine->GetWindowWidth(), m_Engine->GetWindowHeight() ), m_Engine->GetWindowTitle());
	window.setPosition( sf::Vector2i( m_Engine->GetWindowPositionX(), m_Engine->GetWindowPositionY() ) );

	/*
	int32_t map[5][6] = {
		{ 1, 3, 3, 0, 3, 2 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 3, 0, 3, 0, 0 },
		{ 0, 0, 3, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 }
	};

	// in this case without the sqrt function it didnt find the shortest path (2 2; 3 3; 2 4; 1 4)
	//int32_t map[5][6] = {
	//	{ 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 1, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0 },
	//	{ 3, 3, 3, 0, 0, 0 },
	//	{ 0, 2, 0, 0, 0, 0 },
	//};


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

	m_Engine->Initialize();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color::Red);

		m_Engine->Update();
		m_Engine->Render( &window );

		//window.draw();
		window.display();
	}
	
	m_Engine->Release();

    return EXIT_SUCCESS;
}