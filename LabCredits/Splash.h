#pragma once
#ifndef SPLASH
#define SPLASH
///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Header file for our Splash.cpp
///Time: START - 4th/4/2016 - 18:00 -> 21:32	WORK: Wrote the methods and member variables for this class.
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

