#include "License.h"
#include <iostream>


License::License(Game &game, sf::Font font) : m_game(&game), m_comicSans(font), m_textMessage("License", m_comicSans)
{
	m_textMessage.setPosition(100.0f, 100.0f);
	m_textMessage.setColor(sf::Color::Color(0,0,0,255));
}


License::~License()
{
	std::cout << "Destructing License" << std::endl;
}

void License::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	if (m_cumulativeTime.asSeconds() > 2)
	{
		m_game->setGameState(GameState::Splash);
	}
}
void License::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Green);
	window.draw(m_textMessage);
	window.display();
}