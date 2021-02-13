#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Player;

class Game
{
public:
	// delete the copy constructor
	Game(Game const&) = delete;

	// delete the assignment operator
	void operator=(Game const&) = delete;

	/// <summary>
	/// Get the instance of the game.
	/// </summary>
	/// <returns>The instance of the game.</returns>
	static Game& Instance();

	/// <summary>
	/// Get a reference to the game window.
	/// </summary>
	/// <returns>A reference to the game window.</returns>
	const sf::RenderWindow& GetWindow() const;

	/// <summary>
	/// Run the game at a specified framerate.
	/// </summary>
	/// <param name="minFPS">Minimum framerate.</param>
	void Run(sf::Int32 minFPS = 60);

private:
	Game();
	~Game();

	void ProcessWindowEvents(sf::Event::EventType eventType);
	void ProcessInputs();
	void Update(sf::Int32 deltaTime);
	void Render();

private:
	sf::RenderWindow m_Window;

	Player* m_Player;
};

#endif // GAME_HPP