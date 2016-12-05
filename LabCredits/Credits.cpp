#include "Credits.h"
#include <iostream>

/// <summary>
/// Constructor function for our Credits screen.
/// </summary>
/// <param name="game"></param>
/// <param name="font"></param>
Credits::Credits(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textMessage("Credits", m_comicSans)
{
	m_textMessage.setPosition(100.0f, 100.0f);
	m_textMessage.setColor(sf::Color::Color(0, 0, 0, 255));
}

/// <summary>
/// Deconstructor for our License Screen.
/// </summary>
Credits::~Credits()
{
	std::cout << "Destructing credits" << std::endl;
}
/// <summary>
/// Function that handles how long we remain on the credits screen and update any text animations.
/// </summary>
/// <param name="deltaTime"></param>
void Credits::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	if (m_cumulativeTime.asSeconds() > 2)
	{
		m_game->setGameState(GameState::None);
	}
}
/// <summary>
/// render function which handles drawing our text to screen.
/// </summary>
/// <param name="window"></param>
void Credits::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Color(75,0,130,0));
	window.draw(m_textMessage);
	window.display();
}