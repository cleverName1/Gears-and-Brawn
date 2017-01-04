#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

class conversation
{
public:
	sf::RectangleShape conversationWindow;
	sf::Font font;
	sf::Text text;



	conversation();

	void draw(float playerX, float playerY, sf::RenderWindow &window);

	~conversation();
};

