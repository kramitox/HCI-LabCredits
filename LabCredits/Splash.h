#pragma once
#ifndef SPLASH
#define SPLASH

#include <SFML\Graphics.hpp>
#include "Game.h"
class Game;

class Splash
{
public:
	Splash(Game &game, sf::Font font);
	~Splash();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow &window);

private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
};
#endif // !SPLASH

