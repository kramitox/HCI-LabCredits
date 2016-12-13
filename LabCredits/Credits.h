#pragma once
#ifndef CREDITS
#define CREDITS


#include <SFML\Graphics.hpp>
#include "Game.h"
class Game;
class Credits
{
public:
	Credits(Game &game, sf::Font font);
	~Credits();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow &window);

private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	float speed;
	sf::Font m_comicSans;
	sf::Text m_textMessage[20];
	bool m_header[20];
	int m_textIndex;
	int m_timeBetweenTexts;
	std::string m_text;
};

#endif //Credits

