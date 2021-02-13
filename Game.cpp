#include "Game.hpp"
#include "AssetManager.hpp"
#include "Player.hpp"
#include "Target.hpp"

#include <string>

Game::Game() :
	m_Window(sf::VideoMode(918, 515), "Shooting Gallery")
{
	std::srand(std::time(nullptr));

	// load assets
	AssetManager::Instance().LoadSpriteSheet("HUD", "textures/spritesheet_hud.xml");
	AssetManager::Instance().LoadSpriteSheet("Objects", "textures/spritesheet_objects.xml");
	AssetManager::Instance().LoadSpriteSheet("Stall", "textures/spritesheet_stall.xml");

	// create actors
	m_Player = new Player();
	m_Target = new Target(
		Target::TargetTextureNames[std::rand() % 6],
		Target::StandTextureNames[std::rand() % 3],
		sf::Vector2f(400, 400));
}

Game::~Game()
{
	delete m_Player;
	m_Player = nullptr;

	delete m_Target;
	m_Target = nullptr;
}

Game& Game::Instance()
{
	static Game instance;
	return instance;
}

const sf::RenderWindow& Game::GetWindow() const
{
	return m_Window;
}

void Game::Run(sf::Int32 minFPS)
{
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / minFPS);
	sf::Time elapsedTime = sf::Time::Zero;

	sf::Event event;
	while (m_Window.isOpen())
	{
		while (m_Window.pollEvent(event))
		{
			ProcessWindowEvents(event.type);
		}

		ProcessInputs();

		elapsedTime += clock.restart();
		while (elapsedTime >= timePerFrame)
		{
			float deltaTime = timePerFrame.asMilliseconds() * 0.001f;
			Update(deltaTime);
			elapsedTime -= timePerFrame;
		}

		m_Window.clear();
		Render();
		m_Window.display();
	}
}

void Game::ProcessWindowEvents(sf::Event::EventType eventType)
{
	if (eventType == sf::Event::Closed)
	{
		m_Window.close();
	}
}

void Game::ProcessInputs()
{
	m_Target->ProcessInputs();
	m_Player->ProcessInputs();
}

void Game::Update(float deltaTime)
{
	m_Target->Update(deltaTime);
	m_Player->Update(deltaTime);
}

void Game::Render()
{
	m_Window.draw(*m_Target);
	m_Window.draw(*m_Player);
}