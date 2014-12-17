#include "SpriteSheet.h"

#include <stdint.h>
#include <fstream>

using namespace std;
using namespace sf;


struct databuffer {
	char name[255];
	uint32_t x, y, width, height;
};


SpriteSheet* SpriteSheet::getInstance() {
	static SpriteSheet* spriteSheet = nullptr;
	if (!spriteSheet) {
		spriteSheet = new SpriteSheet;
	}
	return spriteSheet;
}

void SpriteSheet::put(const std::string& spritesheet, const string& spritesheetdata) {
	string data;
	databuffer buffer;
	ifstream infile;
	infile.open(spritesheetdata);

	Image ssheet;
	ssheet.loadFromFile(spritesheet);

	while (!infile.eof()) {
		getline(infile, data);

		if (data[0] == '#' || data.empty()) {
			continue;
		}
		
		sscanf(data.c_str(), "%s %i %i %i %i",
			   &buffer.name, &buffer.x, &buffer.y, &buffer.width, &buffer.height);

		IntRect rect(buffer.x, buffer.y, buffer.width, buffer.height);
		Texture texture;
		texture.loadFromImage(ssheet, rect);

		printf("%s %i %i %i %i\n", buffer.name, buffer.x, buffer.y, buffer.width, buffer.height);

		textures[buffer.name] = texture;
	}
	infile.close();
}

Texture& SpriteSheet::get(const string& name) {
	return textures[name];
}

void SpriteSheet::end() {
	delete this;
}