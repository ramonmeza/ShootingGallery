#pragma once
#ifndef	SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include <pugixml.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteSheet
{
public:
	/// <summary>
	/// Instantiate a sprite sheet.
	/// </summary>
	SpriteSheet();

	~SpriteSheet();

	/// <summary>
	/// Load a sprite sheet from the given XML file.
	/// </summary>
	/// <param name="xmlPath">Path to the sprite sheet xml file.</param>
	/// <returns>Whether loading was successful.</returns>
	bool Load(const std::string& xmlPath);

	/// <summary>
	/// Get a specific sprite from the sprite sheet based on its name.
	/// </summary>
	/// <param name="name">Name of the sprite, corresponding to the XML file.</param>
	/// <returns>A pointer to the sprite.</returns>
	sf::Sprite* GetSprite(const std::string& name);

private:
	pugi::xml_document m_Document;
	sf::Texture m_Texture;
};

#endif // SPRITESHEET_HPP
