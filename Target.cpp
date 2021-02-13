#include "Target.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Target::Target()
{

}

Target::~Target()
{
	delete m_Target;
	m_Target = nullptr;

	delete m_Stand;
	m_Stand = nullptr;
}

void Target::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_Stand, states);
	target.draw(*m_Target, states);
}