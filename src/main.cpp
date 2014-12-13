#include <SFML/Graphics.hpp>

using namespace sf;

#define WIDTH 800
#define HEIGHT 600
#define TITLE "TITLE"

/**
* the program entry point
* @param argc the argument count
* @param argv the array containing the arguments
*/
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