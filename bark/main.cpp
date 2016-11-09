#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#define _WIN32_WINNT 0x0500 
#include <windows.h> 
//#include "data.h"

std::vector<sf::Sound*> barks;
std::vector<sf::RectangleShape*> barkdoge;

void playBark(float pitch);
int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Bark!" );
	window.setFramerateLimit(60);

	sf::SoundBuffer buffer;
	buffer.loadFromFile("bark16.wav");
	//buffer.loadFromMemory(bark16_PCM, bark16_Len);

	sf::Texture texture;
	//texture.loadFromMemory(dogeimage, sizeof(dogeimage));
	texture.loadFromFile("bark.png");
	
	for (int i = 0; i < 100; ++i) {
		barks.push_back(new sf::Sound());
		barkdoge.push_back(new sf::RectangleShape(sf::Vector2f(100, 100)));
		barkdoge[i]->setTexture(&texture);
		barks[i]->setBuffer(buffer);
		barks[i]->setVolume(10);
	}

	window.setKeyRepeatEnabled(false);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				playBark(0.5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				playBark(0.6);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				playBark(0.7);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				playBark(0.8);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
				playBark(0.9);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
				playBark(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				playBark(1.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				playBark(1.2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				playBark(1.3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
				playBark(1.4);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
				playBark(1.5);
			}
			
		}

		window.setActive();

		window.clear();
		for (int i = 0; i < barks.size(); i++) {
			if (barks[i]->getStatus() == 2) {
				window.draw(*barkdoge[i]);
			}
		}
		window.display();
	}
	for (int i = 0; i < barks.size(); ++i) {
		delete barks[i];
	}

	for (int i = 0; i < barkdoge.size(); ++i) {
		delete barkdoge[i];
	}

	return 0;
}

void playBark(float pitch) {
	for (int i = 0; i < barks.size(); i++) {
		if (barks[i]->getStatus() != 2) {
			barks[i]->stop();
			barks[i]->setPitch(pitch);
			barkdoge[i]->setPosition(sf::Vector2f(rand() % 1700, rand() % 800));
			barks[i]->play();
			return;
		}
	}
}