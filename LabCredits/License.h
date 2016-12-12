#pragma once
#ifndef LICENSE
#define LICENSE
///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Header file for our License.cpp
///Time: START - 4th/4/2016 - 18:00 -> 21:32	WORK: Wrote the methods and member variables for this class.

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
	sf::Text m_textGame;
	sf::Text m_textMade;
	sf::Text m_textBy;
	sf::Text m_textKeenan;
	int alpha;
};

#endif

