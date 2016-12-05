#include "Splash.h"
#include <iostream>
///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Splash class that handles everything related to our Splash enum. It is the class that handles the Splash screen.
///Time: START - 3rd/4/2016 - 18:00 -> 21:32	WORK: Rewritten Splash class from Pete's document.

/// <summary>
/// Constructor for our Splash Screen. We give it access to the game through a pointer and set the Text string/position/Color.
/// </summary>
/// <param name="game"></param>
/// <param name="font"></param>
Splash::Splash(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textMessage("Spash Screeen", m_comicSans)
{
	m_textMessage.setPosition(100.0f, 100.0f);
	m_textMessage.setColor(sf::Color::White);
}

/// <summary>
/// Deconstructor for our Splash Screen.
/// </summary>
Splash::~Splash()
{
	std::cout << "Destructing Splash" << std::endl;
}
/// <summary>
/// Function to handle how long our SplashScreen remains active and updating any animation we incorporate.
/// </summary>
/// <param name="deltaTime"></param>
void Splash::update()
{
	;
}
void Splash::changeToCreditsState()
{
	m_game->setGameState(GameState::Credits);
}
/// <summary>
/// Function that handles drawing our pretty text to the screen after setting the background colour.
/// </summary>
/// <param name="window"></param>
void Splash::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Red);
	window.draw(m_textMessage);
	window.display();
}

