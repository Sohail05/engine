
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "GameState.h"
#include "script/Scriptengine.hpp"
#include "pathfinder/PathFinder.h"

const int   WINDOWWIDTH  = 1024;
const int   WINDOWHEIGHT = 748;
const int   WINDOWPOSITIONX = 100;
const int   WINDOWPOSITIONY = 0;
const char* WINDOWTITLE = "- Digital Pioneers - GameEngine - Demo v0.001";

/**
* The program entry point
* @param argc the argument count
* @param argv the array containing the arguments
* @return the returncode of the program
*/
int main(int,char**) {

	std::unique_ptr<Engine> Engine(  new Engine( WINDOWTITLE, WINDOWWIDTH, WINDOWHEIGHT, WINDOWPOSITIONX, WINDOWPOSITIONY ) );
	
	int WindowWidth  = Engine->GetWindowWidth();
	int WindowHeight = Engine->GetWindowHeight();

	std::unique_ptr<GameState> gameState( new GameState( WindowWidth, WindowHeight ) );
	std::unique_ptr<MenuState> menuState( new MenuState( WindowWidth, WindowHeight ) );

	Engine->SetGameState( std::move( gameState ) );
	Engine->SetMenuState( std::move( menuState ) );

	sf::RenderWindow window( sf::VideoMode( WindowWidth, WindowHeight ), Engine->GetWindowTitle());
	window.setPosition( sf::Vector2i( Engine->GetWindowPositionX(), Engine->GetWindowPositionY() ) );


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

	Engine->Initialize();

	while( window.isOpen() ) 
	{	
		sf::Event event;
		
		while( window.pollEvent( event ) ) 
		{
			if( event.type == sf::Event::Closed ) 
			{
				window.close();
			}
		}

		window.clear( sf::Color::Black );

		Engine->Update();
		Engine->Render( &window );

		window.display();
	}
	
	Engine->Release();

    return EXIT_SUCCESS;
}
