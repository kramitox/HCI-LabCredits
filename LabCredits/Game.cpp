#include "Game.h"
#include <iostream>

///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Game Class which handles managing our game. It controls what we update and what we render at any given time.
///Time: START - 3rd/4/2016 - 18:00 -> 21:32	WORK: Rewritten Game class from Pete's document.



/// <summary>
/// Game Constructor that handles setting up our window for our game and setting the gameState to License. It then tries to load in the Font file. Later proceeds to create a Splash and License objects.
/// </summary>
Game::Game() : m_window(sf::VideoMode(800, 480), "Credits"), m_currentGameState(GameState::License)
{
	if (!m_comicSans.loadFromFile("c:/windows/fonts/comic.ttf"))
	{
		std::cout << "Problem loading font file" << std::endl;
	}
	m_splashScreen = new Splash(*this, m_comicSans);
	m_licenseScreen = new License(*this, m_comicSans);
	m_credits = new Credits(*this, m_comicSans);
}

/// <summary>
/// Game Deconstructor which handles destroying anything stored on the heap and clearing memory when called.
/// </summary>
Game::~Game()
{
	delete(m_splashScreen);
	delete(m_licenseScreen);
	delete(m_credits);
	std::cout << "Destructing Game" << std::endl;
}
/// <summary>
/// Run method which handles our main gameloop after setting up a clock and frame settings.
/// </summary>
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
/// <summary>
/// Function that sets our games current State equal to whichever state given.
/// </summary>
/// <param name="gameState"></param>
void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}
/// <summary>
/// Function that handles updating any objects in our game.
/// </summary>
/// <param name="time"></param>
void Game::update(sf::Time time)
{
	//Switch to handle all updates dependant on which gameState we are in
	switch (m_currentGameState)
	{
	case GameState::None:
		std::cout << "No GameState" << std::endl;
		break;
	case GameState::License:
		std::cout << "License" << std::endl; 
		m_licenseScreen->update(time);	//Update our License Screen
		break;
	case GameState::Splash:
		std::cout << "Splash" << std::endl;
		m_splashScreen->update();	//Update our Splash Screen
		break;
	case GameState::Credits:
		std::cout << "Credits" << std::endl;
		m_credits->update(time);
		break;
	default:
		break;
	}
}
/// <summary>
/// Function that checks if our window has been closed or not.
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (m_currentGameState == GameState::Splash)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				m_splashScreen->changeToCreditsState();
			}
		}
	}
}
/// <summary>
/// Render function which handles drawing everything to the screen depending on GameState.
/// </summary>
void Game::render()
{
	//Switch to handle rendering dependin on which GameState we are in.
	switch (m_currentGameState)
	{
	case GameState::None:
		m_window.clear(sf::Color::Color(100,149,237,255));	//CornFlower Blue for nostalgia of XNA.
		m_window.display();
		std::cout << "No GameState  Render" << std::endl;
		break;
	case GameState::License:
		std::cout << "License  Render" << std::endl;
		m_licenseScreen->render(m_window);	//Render our License Screen to our window.
		break;
	case GameState::Splash:
		std::cout << "Splash Render" << std::endl;
		m_splashScreen->render(m_window);	//Render our Splash Screen to our window.
		break;
	case GameState::Credits:
		std::cout << "Credits  Render" << std::endl;
		m_credits->render(m_window);
		break;
	default:
		m_window.clear(sf::Color::Blue);
		m_window.display();
		break;
	}
}