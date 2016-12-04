#pragma once
#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include "Splash.h"
#include "License.h"
class Splash;
class License;
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
	sf::Font m_comicSans;
};
#endif // !GAME

