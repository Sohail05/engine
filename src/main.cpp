#include <SFML/Graphics.hpp>

/**
* the program entry point
* @param argc the argument count
* @param argv the array containing the arguments
*/

using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

int main(int argc, char** argv) {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);

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