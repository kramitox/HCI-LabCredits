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
License::License(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textGame("Game", m_comicSans), m_textMade("Made", m_comicSans), m_textBy("By", m_comicSans), m_textKeenan("Keenan", m_comicSans)
{
	m_textGame.setPosition(350,-50);
	m_textGame.setColor(sf::Color::Color(0,0,0,255));

	m_textMade.setPosition(-100, 235);
	m_textMade.setColor(sf::Color::Color(0, 0, 0, 255));

	m_textBy.setPosition(800, 235);
	m_textBy.setColor(sf::Color::Color(0, 0, 0, 255));

	m_textKeenan.setPosition(350, 500);
	m_textKeenan.setColor(sf::Color::Color(0, 0, 0, 255));
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
	if (m_cumulativeTime.asSeconds() < 2)
	{
		m_textGame.setPosition(350, m_textGame.getPosition().y + 2);
		m_textMade.setPosition(m_textMade.getPosition().x + 3.6f, 240);
		m_textBy.setPosition(m_textBy.getPosition().x - 3.1f, 240);
		m_textKeenan.setPosition(350, m_textKeenan.getPosition().y - 1.85f);
	}
	else if (m_cumulativeTime.asSeconds() < 4 && m_cumulativeTime.asSeconds() > 2.3)
	{
		m_textGame.setPosition(m_textGame.getPosition().x + 4, m_textGame.getPosition().y + 4);
		m_textMade.setPosition(m_textMade.getPosition().x - 4, m_textMade.getPosition().y - 4);
		m_textBy.setPosition(m_textBy.getPosition().x + 4, m_textBy.getPosition().y - 4);
		m_textKeenan.setPosition(m_textKeenan.getPosition().x - 4, m_textKeenan.getPosition().y + 4);
	}
	if (m_cumulativeTime.asSeconds() > 4.2)
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
	window.draw(m_textGame);
	window.draw(m_textMade);
	window.draw(m_textBy);
	window.draw(m_textKeenan);
	window.display();
}