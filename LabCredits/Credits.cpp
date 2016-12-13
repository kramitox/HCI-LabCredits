#include "Credits.h"
#include <iostream>
#include <fstream>
/// <summary>
/// Constructor function for our Credits screen.
/// </summary>
/// <param name="game"></param>
/// <param name="font"></param>
std::ifstream stream1;
Credits::Credits(Game &game, sf::Font font) : m_game(&game), m_comicSans(font)
{
	for (int i = 0; i < 20; i++)
	{
		m_textMessage[i].setFont(m_comicSans);
		m_textMessage[i].setCharacterSize(20);
		m_textMessage[i].setPosition(300.0f, 100.0f);
		m_textMessage[i].setColor(sf::Color::Color(0, 0, 0, 255));
	}
	speed = 5;
	
	stream1.open("./ASSETS/TEXT/Credits.txt");
	std::getline(stream1, m_text);
	m_textMessage[m_textIndex].setCharacterSize(35);
	m_textMessage[m_textIndex].setString(m_text);
	m_textMessage[m_textIndex].setPosition(810, 200);
	m_textMessage[m_textIndex].setColor(sf::Color::Cyan);
	m_timeBetweenTexts = 2;
	m_header[m_textIndex] = true;
	m_textIndex++;
}

/// <summary>
/// Deconstructor for our License Screen.
/// </summary>
Credits::~Credits()
{
	
	std::cout << "Destructing credits" << std::endl;
}
/// <summary>
/// Function that handles how long we remain on the credits screen and update any text animations.
/// </summary>
/// <param name="deltaTime"></param>
void Credits::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	std::cout << "updating Credits" << std::endl;
	for (int i = 0; i < 20; i++)
	{

		if (m_header[i])
			m_textMessage[i].setPosition(m_textMessage[i].getPosition().x - speed, 30 * sin(m_textMessage[i].getPosition().x / 5) + 100);
		else
		{
			m_textMessage[i].setPosition(m_textMessage[i].getPosition().x - speed, 50 * cos(m_textMessage[i].getPosition().x / 5) + 250);
		}
	}
	if (m_cumulativeTime.asSeconds() > (m_timeBetweenTexts))
	{
		m_cumulativeTime = m_cumulativeTime.Zero;
		if (stream1.is_open())
		{
			if (std::getline(stream1, m_text))
			{
				if (m_text == "\0")
				{
					
					m_timeBetweenTexts = 5;
					m_header[m_textIndex + 1] = true;
				}
				else if (m_header[m_textIndex])
				{
					m_textMessage[m_textIndex].setCharacterSize(35);
					m_textMessage[m_textIndex].setColor(sf::Color::Cyan);
				}
				else
				{
					m_textMessage[m_textIndex].setCharacterSize(18);
					m_textMessage[m_textIndex].setColor(sf::Color::Magenta);
					m_timeBetweenTexts = 7;
					m_header[m_textIndex] = false;
				}
				m_textMessage[m_textIndex].setString(m_text);
				if (speed < 2)
				{
					m_textMessage[m_textIndex].setPosition(810, 200);
				}
				else
				{
					m_textMessage[m_textIndex].setPosition(300, 500);
				}
				if (speed <= 2)
				{
					speed *= 1.01;
				}
				
				if (m_textIndex < 19)
				{
					m_textIndex++;
				}
				else
				{
					m_textIndex = 0;
				}
			}
			else
			{
				/*
				
				
				
				THIS SECTION HERE TO FINISH!!!!!!!!!!!!!!
				
				*/
				stream1.close();
				bool finished = true;
				for (int i = 0; i < 20; i++)
				{
					if (m_textMessage[i].getPosition().x > -50)
					{
						finished = false;
						break;
					}
					else
					{
						finished = true;
					}
				}
				if (finished)
				{
					(m_game->setGameState(GameState::None));
				}
			}
		}
		
	}
	
	
}
/// <summary>
/// render function which handles drawing our text to screen.
/// </summary>
/// <param name="window"></param>
void Credits::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Color(75,0,130,0));
	for (int i = 0; i < 20; i++)
	{
		window.draw(m_textMessage[i]);
	}
	window.display();
}