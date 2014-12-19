

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "pathfinder/PathFinder.h"

using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

#include "Engine.h"
#include "script/Scriptengine.hpp"

/**
* The program entry point
* @param argc the argument count
* @param argv the array containing the arguments
* @return the returncode of the program
*/
int main(int,char**) {

	std::unique_ptr<Engine> engine(  new Engine( TITLE, WIDTH, HEIGHT, 0, 0 ) );
	
	int WindowWidth  = engine->GetWindowWidth();
	int WindowHeight = engine->GetWindowHeight();

	std::unique_ptr<GameState> gameState( new GameState( WindowWidth, WindowHeight ) );
	std::unique_ptr<MenuState> menuState( new MenuState( WindowWidth, WindowHeight ) );

	engine->SetGameState( std::move( gameState ) );
	engine->SetMenuState( std::move( menuState ) );

	RenderWindow window(VideoMode( WindowWidth, WindowHeight ), engine->GetWindowTitle());
	window.setPosition( sf::Vector2i( engine->GetWindowPositionX(), engine->GetWindowPositionY() ) );


	//int32_t map[5][6] = {
	//	{ 1, 3, 3, 0, 3, 2 },
	//	{ 0, 3, 0, 3, 0, 0 },
	//	{ 0, 3, 0, 3, 0, 0 },
	//	{ 0, 0, 3, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0 }
	//};

	////// in this case without the sqrt function it didnt find the shortest path (2 2; 3 3; 2 4; 1 4)
	////int32_t map[5][6] = {
	////	{ 0, 0, 0, 0, 0, 0 },
	////	{ 0, 0, 0, 1, 0, 0 },
	////	{ 0, 0, 0, 0, 0, 0 },
	////	{ 3, 3, 3, 0, 0, 0 },
	////	{ 0, 2, 0, 0, 0, 0 },
	////};


	//mapdata mapdata;
	//mapdata.map = (int32_t**)map;
	//mapdata.width = 6;
	//mapdata.height = 5;

	//auto searchdata = PathFinder::search(mapdata);
	//if (searchdata->isPathFound()) {
	//	auto path = searchdata->getNodePath();
	//	for (auto vec : *path) {
	//		printf("%i %i\n", vec.x, vec.y);
	//	}
	//}
	//searchdata->release(); // or delete searchdata; // or PathFinder::release(searchdata);


	/* assertion failing - prob due to void main() - DMG 
	ScriptEngine as;
	as.loadScript("test.as");
	as.runScript("test.as", "void main()");
	*/

	engine->Initialize();

	while (window.isOpen()) {
		
		Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color::Black);

		engine->Update();
		engine->Render( &window );

		window.display();
	}
	
	engine->Release();

    return EXIT_SUCCESS;
}
