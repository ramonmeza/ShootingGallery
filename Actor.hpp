#pragma once
#ifndef	ACTOR_HPP
#define ACTOR_HPP

#include <SFML/Config.hpp>

class Actor
{
public:
	virtual void ProcessInputs() = 0;
	virtual void Update(sf::Int32 deltaTime) = 0;
};

#endif // ACTOR_HPP