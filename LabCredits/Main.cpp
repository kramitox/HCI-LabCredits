#ifdef _DEBUG
#pragma comment (lib, "sfml-graphics-d.lib")
#pragma comment (lib, "sfml-audio-d.lib")
#pragma comment (lib, "sfml-system-d.lib")
#pragma comment (lib, "sfml-window-d.lib")
#pragma comment (lib, "sfml-main-d.lib")
#pragma comment (lib, "sfml-network-d.lib")
#else
#pragma comment (lib, "sfml-graphics.lib")
#pragma comment (lib, "sfml-audio.lib")
#pragma comment (lib, "sfml-system.lib")
#pragma comment (lib, "sfml-window.lib")
#pragma comment (lib, "sfml-main.lib")
#pragma comment (lib, "sfml-network.lib")
#endif

#include "Game.h"

///NAME: Keenan McEntee
///STUDENT ID: C00201892
///Version: 1.01
///Description: Project to show the use of Enums for GameStates and how to move between different Game States.
///Time: START - 3rd/4/2016 - 18:00 -> 21:32	WORK: Rewrote the classes and headers from petes document in to the project.
///		 EDIT  - 4th/4/2016 - 22:00 -> 22:43	WORK: Added the License screen to the project and commented it.
///


///Main method. Entry Point for our project which handles getting us to our game loop.
int main()
{
	Game game;
	game.run();
}