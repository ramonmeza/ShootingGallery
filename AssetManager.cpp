#include "AssetManager.hpp"
#include "SpriteSheet.hpp"

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
	// delete sprite sheets from the map
	for (auto& sheet : m_SpriteSheets)
	{
		delete sheet.second;
		sheet.second = nullptr;
	}
	m_SpriteSheets.clear();
}

AssetManager& AssetManager::Instance()
{
	static AssetManager instance;
	return instance;
}

bool AssetManager::LoadSpriteSheet(const std::string& key, const std::string& xmlPath)
{
	// make sure key doesn't exist
	if (m_SpriteSheets.find(key) == m_SpriteSheets.end())
	{
		// load the sprite sheet
		SpriteSheet* sheet = new SpriteSheet();
		if (sheet->Load(xmlPath))
		{
			// if the sprite sheet was created, add it to our map
			m_SpriteSheets.insert(std::pair<std::string, SpriteSheet*>(key, sheet));
			return true;
		}

		// delete memory if the sprite sheet wasn't loaded properly
		delete sheet;
		sheet = nullptr;
	}

	return false;
}

sf::Sprite* AssetManager::GetSprite(const std::string& key, const std::string& name)
{
	// make sure key exists
	if (m_SpriteSheets.find(key) != m_SpriteSheets.end())
	{
		// return the sprite from the sprite sheet
		return m_SpriteSheets[key]->GetSprite(name);
	}

	return nullptr;
}