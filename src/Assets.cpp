#include "Assets.h"

#include <stdint.h>
#include <fstream>

using namespace std;
using namespace sf;

map<std::string, sf::Texture> Assets::s_textures;


struct databuffer
{
	char name[255];
	uint32_t x, y, width, height;
};


void Assets::putSpriteSheet(const std::string& spritesheet, const string& spritesheetdata)
{
	string data;
	databuffer buffer;
	ifstream infile;
	infile.open(spritesheetdata);

	Image ssheet;
	ssheet.loadFromFile(spritesheet);

	while (!infile.eof()) 
	{
		getline(infile, data);

		if (data[0] == '#' || data.empty())
		{
			continue;
		}
		
		sscanf(data.c_str(), "%s %i %i %i %i",
			   &buffer.name, &buffer.x, &buffer.y, &buffer.width, &buffer.height);

		IntRect rect(buffer.x, buffer.y, buffer.width, buffer.height);
		Texture texture;
		texture.loadFromImage(ssheet, rect);

		s_textures[buffer.name] = texture;
	}

	infile.close();
}

Texture& Assets::getTexture(const string& name)
{
	return s_textures[name];
}