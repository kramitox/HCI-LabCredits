#pragma once
#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include "Splash.h"
#include "License.h"
#include "Credits.h"
///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Description: Header file for our game class.
///Time: START - 3rd/4/2016 - 18:00 -> 21:32	WORK: Rewritten Game class from Pete's document.

class Splash;
class License;
class Credits;
///Enum to handle all the different states our game can be in. (Pause, Play, etc.)
enum class GameState{None,License,Splash,Credits};

class Game
{
public:
	Game();
	~Game();

	void run();
	GameState m_currentGameState;
	void setGameState(GameState gameState);

private:
	void processEvents();
	void update(sf::Time);
	void render();

	sf::RenderWindow m_window;
	Splash *m_splashScreen;
	License *m_licenseScreen;
	Credits *m_credits;
	sf::Font m_comicSans;
};
#endif // !GAME

