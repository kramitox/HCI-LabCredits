#include "License.h"
#include <iostream>
///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Class that handles all updates and renders for when in the License GameState
///Time: START - 4th/4/2016 - 18:00 -> 21:32	WORK: Wrote the code following the Splash Screen as a Guide. To be Edited on Part 2 of project.

/// <summary>
/// Constructor function for our License screen. It sets the text font, string, position and color.
/// </summary>
/// <param name="game"></param>
/// <param name="font"></param>
License::License(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textMessage("License", m_comicSans)
{
	m_textMessage.setPosition(100.0f, 100.0f);
	m_textMessage.setColor(sf::Color::Color(0,0,0,255));
}

/// <summary>
/// Deconstructor for our License Screen.
/// </summary>
License::~License()
{
	std::cout << "Destructing License" << std::endl;
}
/// <summary>
/// Function that handles how long we remain on the License screen and update any text animations.
/// </summary>
/// <param name="deltaTime"></param>
void License::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	if (m_cumulativeTime.asSeconds() > 2)
	{
		m_game->setGameState(GameState::Splash);
	}
}
/// <summary>
/// Render Function which handles drawing the pretty pictures or text to screen.
/// </summary>
/// <param name="window"></param>
void License::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Green);
	window.draw(m_textMessage);
	window.display();
}