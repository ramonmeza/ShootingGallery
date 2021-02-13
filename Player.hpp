#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Actor.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Player : public Actor, public sf::Drawable
{
public:
	Player();
	~Player();

	virtual void ProcessInputs();
	virtual void Update(sf::Int32 deltaTime);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	const sf::Vector2f m_GunOffset = sf::Vector2f(93, 73);

	sf::Sprite* m_Crosshair;
	sf::Sprite* m_Gun;
};

#endif // PLAYER_HPP