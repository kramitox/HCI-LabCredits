#include "Game.h"
#include <iostream>


Game::Game() : m_window(sf::VideoMode(800, 480), "Credits"), m_currentGameState(GameState::License)
{
	if (!m_comicSans.loadFromFile("c:/windows/fonts/comic.ttf"))
	{
		std::cout << "Problem loading font file" << std::endl;
	}
	m_splashScreen = new Splash(*this, m_comicSans);
	m_licenseScreen = new License(*this, m_comicSans);
}


Game::~Game()
{
	delete(m_splashScreen);
	std::cout << "Destructing Game" << std::endl;
}
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}
void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

void Game::update(sf::Time time)
{
	switch (m_currentGameState)
	{
	case GameState::None:
		std::cout << "No GameState" << std::endl;
		break;
	case GameState::License:
		std::cout << "License" << std::endl;
		m_licenseScreen->update(time);
		break;
	case GameState::Splash:
		std::cout << "Splash" << std::endl;
		m_splashScreen->update(time);
		break;
	case GameState::Credits:
		std::cout << "Credits" << std::endl;
		break;
	default:
		break;
	}
}
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}
void Game::render()
{
	switch (m_currentGameState)
	{
	case GameState::None:
		m_window.clear(sf::Color::Color(100,149,237,255));
		m_window.display();
		std::cout << "No GameState  Render" << std::endl;
		break;
	case GameState::License:
		std::cout << "License  Render" << std::endl;
		m_licenseScreen->render(m_window);
		break;
	case GameState::Splash:
		std::cout << "Splash Render" << std::endl;
		m_splashScreen->render(m_window);
		break;
	case GameState::Credits:
		std::cout << "Credits  Render" << std::endl;
		break;
	default:
		m_window.clear(sf::Color::Blue);
		m_window.display();
		break;
	}
}