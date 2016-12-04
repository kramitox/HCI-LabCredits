#pragma once
#ifndef LICENSE
#define LICENSE

#include <SFML\Graphics.hpp>
#include "Game.h"
class Game;

class License
{
public:
	License(Game &game, sf::Font font);
	~License();


	void update(sf::Time deltaTime);
	void render(sf::RenderWindow &window);

private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
};

#endif

