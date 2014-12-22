#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Assets
{
public:
	static void putSpriteSheet(const std::string& spritesheet, const std::string& spritesheetdata);
	static sf::Texture& getTexture(const std::string& name);
private:
	static std::map<std::string, sf::Texture> s_textures;
};

