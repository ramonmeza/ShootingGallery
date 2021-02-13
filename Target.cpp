#include "Target.hpp"
#include "AssetManager.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

const std::string Target::TargetTextureNames[6] = {
	"target_back_outline.png",
	"target_colored_outline.png",
	"target_red1_outline.png",
	"target_red2_outline.png",
	"target_red3_outline.png",
	"target_white_outline.png"
};

const std::string Target::StandTextureNames[3] = {
	"stick_metal_outline.png",
	"stick_woodFixed_outline.png",
	"stick_wood_outline.png"
};

Target::Target(const std::string& targetTextureName,
			   const std::string& stallTextureName,
			   sf::Vector2f position)
{
	m_Target = AssetManager::Instance().GetSprite("Objects", targetTextureName);

	float width = m_Target->getLocalBounds().width / 2.0f;
	float height = m_Target->getLocalBounds().height - 10;
	m_Target->setOrigin(width, height);

	m_Stand = AssetManager::Instance().GetSprite("Objects", stallTextureName);
	width = m_Stand->getLocalBounds().width / 2.0f;
	m_Stand->setOrigin(width, 0);

	m_FinalPosition = position;
	SetPosition(m_FinalPosition.x, m_FinalPosition.y + 100);

	m_Speed = 100.0;
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

void Target::ProcessInputs()
{

}

void Target::Update(float deltaTime)
{
	// if the current position is lower than the final position
	sf::Vector2f pos = GetPosition();
	if (pos.y > m_FinalPosition.y)
	{
		// move up
		SetPosition(pos.x, pos.y - (m_Speed * deltaTime));
	}
}

void Target::SetPosition(float x, float y)
{
	m_Stand->setPosition(x, y);
	m_Target->setPosition(x, y);
}

sf::Vector2f Target::GetPosition()
{
	return m_Target->getPosition();
}