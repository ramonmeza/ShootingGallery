#include "SpriteSheet.hpp"

#include <filesystem>
#include <pugixml.hpp>

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::~SpriteSheet()
{

}

bool SpriteSheet::Load(const std::string& xmlPath)
{
	// check if xml file exists
	if(std::filesystem::exists(xmlPath))
	{
		// load the xml document
		if (m_Document.load_file(xmlPath.c_str()))
		{
			// get the texture path
			const std::string texturePath =
				std::string("textures/") + 
				m_Document.child("TextureAtlas").attribute("imagePath").value();

			// check if texture file exists
			if (std::filesystem::exists(texturePath))
			{
				// load the texture
				m_Texture.loadFromFile(texturePath);
				return true;
			}
		}
	}

	return false;
}

sf::Sprite* SpriteSheet::GetSprite(const std::string& name)
{
	// get the attribute node with the name
	pugi::xml_node subTexture = m_Document.child("TextureAtlas")
		.find_child_by_attribute("SubTexture", "name", name.c_str());

	// make sure the node was found
	if (subTexture != NULL)
	{
		// get the sub texture's attribute values
		int x = subTexture.attribute("x").as_int();
		int y = subTexture.attribute("y").as_int();
		int width = subTexture.attribute("width").as_int();
		int height = subTexture.attribute("height").as_int();

		// create the texture rect where the desired sprite is on the texture
		const sf::IntRect textureRect = sf::IntRect(x, y, width, height);

		// create the sprite
		sf::Sprite* spr = new sf::Sprite(m_Texture);
		spr->setTextureRect(textureRect);

		// return the sprite
		return spr;
	}

	return nullptr;
}