#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SpriteSheet {
public:
	static SpriteSheet* getInstance();
	
	void put(const std::string& spritesheet, const std::string& spritesheetdata);
	sf::Texture& get(const std::string& name);
	void end();
private:
	std::map<std::string, sf::Texture> textures;
};

