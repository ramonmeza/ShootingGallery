#pragma once
#ifndef TARGET_HPP
#define TARGET_HPP

#include "Actor.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Target : public Actor, public sf::Drawable
{
public:
	Target();
	~Target();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite* m_Target;
	sf::Sprite* m_Stand;
};

#endif // TARGET_HPP