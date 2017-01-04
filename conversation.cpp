#include "conversation.h"



conversation::conversation()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "The font: arial.ttf could not load. \n";
	}




}




void conversation::draw(float playerX, float playerY, sf::RenderWindow &window){

	sf::RectangleShape conversationWindow(sf::Vector2f(400, 200));
	conversationWindow.setPosition(sf::Vector2f(playerX - 200, playerY - 210));
	window.draw(conversationWindow);

	text.setFont(font);
	text.setCharacterSize(12);
	text.setColor(sf::Color::Black);
	text.setString("I am fancySquirrel the IV:th. Would you maybe consider abstaining \nfrom lugging those rock_projectile's at me ol chap?");
	text.setPosition(sf::Vector2f(playerX - 190, playerY - 200));
	window.draw(text);

}


conversation::~conversation()
{
}
