#pragma once
#ifndef TARGET_HPP
#define TARGET_HPP

#include "Actor.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

class Target : public Actor, public sf::Drawable
{
public:
	Target(const std::string& targetTextureName, 
		   const std::string& stallTextureName, 
		   sf::Vector2f position);
	~Target();

	virtual void ProcessInputs();
	virtual void Update(float deltaTime);

	void SetPosition(float x, float y);
	sf::Vector2f GetPosition();

public:
	static const std::string TargetTextureNames[6];
	static const std::string StandTextureNames[3];

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Vector2f m_FinalPosition;
	float m_Speed;

	sf::Sprite* m_Target;
	sf::Sprite* m_Stand;
};

#endif // TARGET_HPP