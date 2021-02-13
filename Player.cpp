#include "Player.hpp"
#include "AssetManager.hpp"
#include "Game.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>

Player::Player()
{
	m_Crosshair = AssetManager::Instance().GetSprite("HUD", "crosshair_white_large.png");

	float width = m_Crosshair->getLocalBounds().width / 2.0f;
	float height = m_Crosshair->getLocalBounds().height / 2.0f;
	m_Crosshair->setOrigin(width, height);

	m_Gun = AssetManager::Instance().GetSprite("Objects", "rifle.png");
}

Player::~Player()
{
	delete m_Crosshair;
	m_Crosshair = nullptr;

	delete m_Gun;
	m_Gun = nullptr;
}

void Player::ProcessInputs()
{

}

void Player::Update(float deltaTime)
{
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(Game::Instance().GetWindow()));
	m_Crosshair->setPosition(mousePos);

	sf::Vector2f gunPos = mousePos + m_GunOffset;
	m_Gun->setPosition(gunPos);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_Gun, states);
	target.draw(*m_Crosshair, states);
}