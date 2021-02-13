#pragma once
#ifndef	ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <map>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

class SpriteSheet;

class AssetManager
{
public:
	// delete the copy constructor
	AssetManager(AssetManager const&) = delete;

	// delete the assignment operator
	void operator=(AssetManager const&) = delete;

	/// <summary>
	/// Get the instance of the AssetManager.
	/// </summary>
	/// <returns>A reference to the AssetManager object.</returns>
	static AssetManager& Instance();

	/// <summary>
	/// Load a sprite sheet into the asset manager.
	/// </summary>
	///	<param name="key">Key to use when referencing the sprite sheet.</param>
	/// <param name="xmlPath">Path to the sprite sheet xml file.</param>
	/// <returns>Whether the loading was successful.</returns>
	bool LoadSpriteSheet(const std::string& key, const std::string& xmlPath);

	/// <summary>
	/// Get a specific sprite from the sprite sheet based on its name.
	/// </summary>
	/// <param name="key">Key for the sprite sheet.</param>
	/// <param name="name">Name of the sprite, corresponding to the XML file.</param>
	/// <returns>A pointer to the sprite.</returns>
	sf::Sprite* GetSprite(const std::string& key, const std::string& name);

private:
	AssetManager();
	~AssetManager();

private:
	/// <summary>
	/// Map for sprite sheets. 
	/// </summary>
	std::map<std::string, SpriteSheet*> m_SpriteSheets;
};

#endif // ASSETMANAGER_HPP