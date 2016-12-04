#include "Splash.h"
#include <iostream>


Splash::Splash(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textMessage("Spash Screeen", m_comicSans)
{
	m_textMessage.setPosition(100.0f, 100.0f);
	m_textMessage.setColor(sf::Color::White);
}


Splash::~Splash()
{
	std::cout << "Destructing Splash" << std::endl;
}

void Splash::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	if (m_cumulativeTime.asSeconds() > 3)
	{
		m_game->setGameState(GameState::None);
	}
}
void Splash::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Red);
	window.draw(m_textMessage);
	window.display();
}

