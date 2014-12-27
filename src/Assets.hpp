#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Assets
{
public:
	//////////////////////////////////////////////////
	// @brief loads a sprite sheet from file
	// 
	// @param spritesheet sprite sheet image
	// @param spritesheetdata sprite sheet description
	//////////////////////////////////////////////////
	static void putSpriteSheet(const std::string& spritesheet, const std::string& spritesheetdata);

	///////////////////////////////////////////////
	// @param name the key in the sprite sheet data
	// @returns the texture
	///////////////////////////////////////////////
	static sf::Texture& getTexture(const std::string& name);
private:
	static std::map<std::string, sf::Texture> s_textures;
};

