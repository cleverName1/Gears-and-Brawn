#include <iostream>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "enemy.h"
#include "matter.h"
#include "animatedmatter.h"
#include "tile.h"
#include "projectile.h"
#include "conversation.h"
#include <vector>
#include "world.h"
using namespace std;




int main() {

	// Used to measure fps
	int framesPassed = 0;
	sf::Clock fpsClock;

	// Used to limit the time of the red flash when an enemy is hit by a projectile
	sf::Clock oneHundredMillisecondClock;

	// Used to limit damage dealt.
	sf::Clock twoHundredMillisecondClock;

	// Used to limit firing speed
	sf::Clock oneSecondClock;

	// Used to control enemy Movement
	sf::Clock sixSecondClock;

	// Used to erase projectiles
	sf::Clock fiveSecondClock;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	bool firstLoop = true;
	bool conversationActive = false;



	sf::RenderWindow window(sf::VideoMode(1280, 800), "Gears and Brawn", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::FloatRect(0, 0, 800, 500));



	// Sätter max-framerate
	window.setFramerateLimit(100);

	


	// ------------------------------------------------------------------------------- Load and set textures
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("sin_spritesheet_60px.png"))
	{
		std::cout << "sin_spritesheet_60px.png failed to load. /n";
	}

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("fancySquirrel_spritesheet_60px.png"))
	{
		std::cout << "fancySquirrel_spritesheet_60px.png failed to load. /n";
	}

	sf::Texture snowMatterTexture;
	if (!snowMatterTexture.loadFromFile("snowmatter spritesheet.png"))
	{
		std::cout << "snowmatter spritesheet.png failed to load. /n";
	}

	sf::Texture treeWindTexture;
	if (!treeWindTexture.loadFromFile("treeWind_spritesheet_1260x140px.png"))
	{
		std::cout << "treeWind_spritesheet_1260x140px.png failed to load. /n";
	}

	sf::Texture rockProjectileTexture;
	if (!rockProjectileTexture.loadFromFile("rock_projectile.png"))
	{
		std::cout << "rock_projectile.png failed to load. /n";
	}

	sf::Texture tileTexture;
	if (!tileTexture.loadFromFile("tiles_spritesheet.png"))
	{
		std::cout << "tiles_spritesheet.png failed to load. /n";
	}



	// ------------------------------------------------------------------------------- 

	class player Player1;
	Player1.sprite.setTexture(playerTexture);

	class conversation Conversation;


	// matter array
	vector<matter>::const_iterator iter;
	vector<matter> matterArray;

	// matter objects, passed to the function in order is: Width, Height, X, Y of the desired hitBox in relation to the sprite.
	class matter snowMatter(70, 50, 20, 50);

	// World Array
	vector<world>::const_iterator iter8;
	vector<world> worldArray;

	// World Object
    class world tile(30, 30, 0, 0);

	// animatedmatter array
	vector<animatedmatter>::const_iterator iter4;
	vector<animatedmatter> animatedmatterArray;

	// animatedmatter objects

	class animatedmatter TreeWind;

	/*
	// tile array
	vector<tile>::const_iterator iter2;
	vector<tile> tileArray;

	// tile objects
	class tile Grass;
	class tile Snow;
	class tile mountain;
	class tile background;
	*/

	// enemy array
	vector<enemy>::const_iterator iter3;
	vector<enemy> enemyArray;

	// enemy objects
	class enemy Enemy;

	// enemy array
	vector<int>::const_iterator iter7;
	vector<int> enemyHealthArray;

	// projectile array
	vector<projectile>::const_iterator iter5;
	vector<projectile> projectileArray;

	// projectile objects
	class projectile ProjectileRock;


	vector<int>::const_iterator iter6;
	vector<int> projectileDirectionsArray;


	
	Enemy.sprite.setTexture(enemyTexture);
	TreeWind.sprite.setTexture(treeWindTexture);
	ProjectileRock.sprite.setTexture(rockProjectileTexture);
	snowMatter.sprite.setTexture(snowMatterTexture);
	tile.sprite.setTexture(tileTexture);




	// Loopen som håller fönstret öppet
	while (window.isOpen())
	{


		// ----------------------------------------------------------------------------------------------------------- This is where the content of the vectors is added to the game
		if (firstLoop == true) {


			snowMatter.sprite.setPosition(400, 400);
			snowMatter.sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
			matterArray.push_back(snowMatter);


			snowMatter.sprite.setPosition(400, 534);
			snowMatter.sprite.setTextureRect(sf::IntRect(100, 0, 100, 100));
			matterArray.push_back(snowMatter);

			Enemy.sprite.setPosition(325, 725);
			enemyArray.push_back(Enemy);
			enemyHealthArray.push_back(Enemy.getHealth());


			/*
			TreeWind.sprite.setPosition(0, 0);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(130, 20);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(400, 34);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(345, 56);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(123, 76);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(346, 234);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(234, 545);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(454, 345);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(124, 657);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(67, 63);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(47, 453);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);

			TreeWind.sprite.setPosition(17, 233);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);


			*/



			

			// Variables for for-loop drawing
			int lastValueX;
			int lastValueY;


			


			/*
			// Paint background
			lastValueX = 0;
			lastValueY = 0;
			for (int i = 0; i != 15; i++)
			{

				background.sprite.setPosition(lastValueX, lastValueY);
				tileArray.push_back(background);
				lastValueX += 800;
				if (lastValueX >= 700) {
					lastValueY += 800;
					lastValueX = 0;
				}
			}
			*/

			



			//------------------------------------------------------------------------------------------------------------------------------------------------------ Building the tiles



            int map[900] = { 
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
				1, 1, 1, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 13, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 12, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 10, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 ,1, 1, 1,
				1, 1, 1, 9, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 8 ,1, 1, 1,
				1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
				1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
				1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1

			};

            lastValueX = 0;
            lastValueY = 0;

			for (int i = 0; i != 900; i++)

			{



				tile.sprite.setTextureRect(sf::IntRect(map[i] * 30, 0, 30, 30));
				

					tile.sprite.setPosition(lastValueX, lastValueY);
					if (map[i] == 0 || map[i] == 1) {
						tile.setTileIsWalkable(true);
					}
					if (map[i] == 2 || map[i] == 3 || map[i] == 4 || map[i] == 5 || map[i] == 6 || map[i] == 7 || map[i] == 8 || map[i] == 9 || map[i] == 10 || map[i] == 11 || map[i] == 12 || map[i] == 13) {
						tile.setTileIsWalkable(false);
					}
					worldArray.push_back(tile);


					lastValueX += 30;
					if (lastValueX >= 900) {
						lastValueY += 30;
						lastValueX = 0;
					
				}

			}







			//------------------------------------------------------------------------------------------------------------------------------------------------------
	
	



			firstLoop = false;
		}
		// -----------------------------------------------------------------------------------------------------------




		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// Om krysset klickas ska fönstret stängas
			case sf::Event::Closed: window.close();
				window.close();
			}
		}


		// These variables are used for collision detection with the player.
		float playerWidth = Player1.hitRect.getGlobalBounds().width;
		float playerHeight = Player1.hitRect.getGlobalBounds().height;
		float playerX = Player1.hitRect.getPosition().x;
		float playerY = Player1.hitRect.getPosition().y;


		framesPassed++;
		if (fpsClock.getElapsedTime().asSeconds() >= 1) {
			std::cout << framesPassed << endl;
			framesPassed = 0;
			fpsClock.restart();
		}


		// Create projectile with space
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (oneSecondClock.getElapsedTime().asSeconds() >= 1) {
				ProjectileRock.sprite.setPosition(playerX + 20, playerY + 20);
				projectileArray.push_back(ProjectileRock);
				projectileDirectionsArray.push_back(Player1.facingDirection());
				std::cout << "Pew pew \n";
				oneSecondClock.restart();
				fiveSecondClock.restart();
			}
		}




		window.clear();


		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION world
		// Draw tile to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter8 = worldArray.begin(); iter8 != worldArray.end(); iter8++)
		{
			worldArray[counter1].update(worldArray[counter1].sprite.getPosition().x, worldArray[counter1].sprite.getPosition().y);

			window.draw(worldArray[counter1].sprite);
			counter1++;
		}
		

			
			// Check collision with worldArray, iter is set to the begining of the array
			counter1 = 0;
		for (iter8 = worldArray.begin(); iter8 != worldArray.end(); iter8++)
		{
			if (Player1.hitRect.getGlobalBounds().intersects(worldArray[counter1].hitRect.getGlobalBounds()))
			{
				if (worldArray[counter1].tileIsWalkable() == false) {
					float direction1 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[0];
					float direction2 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[1];
					float direction3 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[2];
					float direction4 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[3];
					Player1.collision(direction1, direction2, direction3, direction4);
					//std::cout << direction1 << " | " << direction2 << " | " << direction3 << " | " << direction4 << " | " << endl;					
				}
			}
			counter1++;
		}

			
			// ---------------------------------------------------------------------------------------------------------------


		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION matter
		// Draw matter to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter = matterArray.begin(); iter != matterArray.end(); iter++)
		{
			matterArray[counter1].update(matterArray[counter1].sprite.getPosition().x, matterArray[counter1].sprite.getPosition().y);
			window.draw(matterArray[counter1].sprite);
			counter1++;
		}


		// Check collision with matterArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter = matterArray.begin(); iter != matterArray.end(); iter++)
		{
			// Check if player is colliding with objects from the matterArray.
			if (Player1.hitRect.getGlobalBounds().intersects(matterArray[counter1].hitRect.getGlobalBounds()))
			{
				float direction1 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[0];
				float direction2 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[1];
				float direction3 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[2];
				float direction4 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[3];
				Player1.collision(direction1, direction2, direction3, direction4);
			}

			counter2 = 0;
			// Cycle through the projectileArray for each piece if matter.
			for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
			{
				// If a member of projectileArray intersects a member of matterArray
				if (projectileArray[counter2].sprite.getGlobalBounds().intersects(matterArray[counter1].hitRect.getGlobalBounds()))
				{
					if (projectileDirectionsArray.at(counter2) != 5) {
						// Set the projectile to a direction that equals stop
						projectileDirectionsArray.at(counter2) = 5;
					}		
				}
				counter2++;
			}



			counter1++;
		}

		// ---------------------------------------------------------------------------------------------------------------



		// -------------------------------------------------------------------------------------------------------------- DRAW + MOVE + COLLISION enemy

		// Move enemy around the screen
		if (enemyArray.size() != 0) {
			counter1 = 0;
			for (iter7 = enemyHealthArray.begin(); iter7 != enemyHealthArray.end(); iter7++)
			{
				if (enemyHealthArray[counter1] > 0) {
					enemyArray[counter1].update(sixSecondClock.getElapsedTime().asSeconds());
				}
				counter1++;
			}



			// Draw enemy to the screen, iter is set to the begining of the array
			counter1 = 0;
			for (iter3 = enemyArray.begin(); iter3 != enemyArray.end(); iter3++)
			{

				window.draw(enemyArray[counter1].sprite);
				counter1++;
			}



			counter1 = 0;
			// Check collision with enemyArray, iter is set to the begining of the array
			for (iter3 = enemyArray.begin(); iter3 != enemyArray.end(); iter3++)
			{
				// Check if enemy has been red for 100 millisedconds due to damage, if so return color to original.
				if (oneHundredMillisecondClock.getElapsedTime().asMilliseconds() >= 100) {
					enemyArray[counter1].sprite.setColor(sf::Color(255, 255, 255, 255));
				}
				counter2 = 0;

				//--------------------------------------------------------------------------------------- PLAYER / ENEMY intersecion
				if (Player1.sprite.getGlobalBounds().intersects(enemyArray[counter1].sprite.getGlobalBounds()))
				{

					// Cycle though the enemyHealthArray for every member of enemyArray
					for (iter7 = enemyHealthArray.begin(); iter7 != enemyHealthArray.end(); iter7++)
					{
						// Check if the enemy is defeated or not (health = 0)
						if (enemyHealthArray[counter1] <= 0) {
						

							if (conversationActive == true) {
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
									conversationActive = false;

								}
							}

							// Initiate conversation with E
							if (conversationActive == false) {
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
									//startConversation(playerX, playerY, window);
									conversationActive = true;

								}
							}



						}
					}

				}
				else {
					conversationActive = false;
				}
				//--------------------------------------------------------------------------------------- PLAYER / ENEMY intersecion END


				//--------------------------------------------------------------------------------------- PROJECTILE / ENEMY intersecion

				// Cycle through the projectileArray for each enemy.
				for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
				{
					// If a member of projectileArray intersects a member of enemyArray
					if (projectileArray[counter2].sprite.getGlobalBounds().intersects(enemyArray[counter1].hitRect.getGlobalBounds()))
					{
						// Cycle though the enemyHealthArray for every member of projectileArray
						for (iter7 = enemyHealthArray.begin(); iter7 != enemyHealthArray.end(); iter7++)
						{

							// See if this particular enemy has any health left, execute code to reduce health or for hitting a corpse.
							if (enemyHealthArray[counter1] <= 0) {

								// If the Projectile is moving, it hit a dead target.
								if (projectileDirectionsArray.at(counter2) != 5) {
									// If Projectile hits target, set its movement direction to 5, which represents no direciton, stopping it.
									projectileDirectionsArray.at(counter2) = 5;
									std::cout << "Dead!\n";
									enemyArray[counter1].sprite.setColor(sf::Color::Red);
									oneHundredMillisecondClock.restart();
									enemyArray[counter1].sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));

								}


							}
							else {
								// If enemy is not dead, deal damage as long as this projectile has not dealt this target enemy damage in the past second.
								if (twoHundredMillisecondClock.getElapsedTime().asMilliseconds() >= 200) {


									// If the Projectile is moving, deal damage.
									if (projectileDirectionsArray.at(counter2) != 5) {
										// If Projectile hits target, set its movement direction to 5, which represents no direciton, stopping it.
										projectileDirectionsArray.at(counter2) = 5;
										enemyHealthArray.at(counter1) -= 2;
										std::cout << "Hp left: " << enemyHealthArray[counter1] << endl;
										enemyArray[counter1].sprite.setColor(sf::Color::Red);
										oneHundredMillisecondClock.restart();

										// If the shoot kills the enemy, set appropriate texture.
										if (enemyHealthArray[counter1] <= 0) {
											enemyArray[counter1].sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));
										}
									}
									twoHundredMillisecondClock.restart();
								}
							}
						}
					}
					counter2++;
				}
				//--------------------------------------------------------------------------------------- PROJECTILE / ENEMY intersecion END

				counter1++;
			}
		}

		// ---------------------------------------------------------------------------------------------------------------

		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION animatedmatter
		// Animate animatedmatter objects with update function.
		counter1 = 0;
		for (iter4 = animatedmatterArray.begin(); iter4 != animatedmatterArray.end(); iter4++)
		{
			animatedmatterArray[counter1].update();
			counter1++;
		}

		// Draw animatedmatter to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter4 = animatedmatterArray.begin(); iter4 != animatedmatterArray.end(); iter4++)
		{

			window.draw(animatedmatterArray[counter1].sprite);
			counter1++;
		}


		// Check collision with animatedArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter4 = animatedmatterArray.begin(); iter4 != animatedmatterArray.end(); iter4++)
		{

			if (Player1.hitRect.getGlobalBounds().intersects(animatedmatterArray[counter1].hitRect.getGlobalBounds()))
			{
				float direction1 = animatedmatterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[0];
				float direction2 = animatedmatterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[1];
				float direction3 = animatedmatterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[2];
				float direction4 = animatedmatterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[3];
				Player1.collision(direction1, direction2, direction3, direction4);
			}


			counter2 = 0;
			// Cycle through the projectileArray for each piece if matter.
			for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
			{
				// If a member of projectileArray intersects a member of matterArray
				if (projectileArray[counter2].sprite.getGlobalBounds().intersects(animatedmatterArray[counter1].hitRect.getGlobalBounds()))
				{
					if (projectileDirectionsArray.at(counter2) != 5) {
						// Set the projectile to a direction that equals stop
						projectileDirectionsArray.at(counter2) = 5;
					}
				}
				counter2++;
			}




			counter1++;
		}

		// ---------------------------------------------------------------------------------------------------------------

		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION projectile

		// Move projectile objects with update function.

		counter1 = 0;
		for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
		{
			// Direction array saves the direction of every individual projectile.
			int projectileDirection = projectileDirectionsArray[counter1];

			// Update the position of the projectile based on its direction
			projectileArray[counter1].update(projectileDirection);
			counter1++;
		}

		// Draw projectile to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
		{
			window.draw(projectileArray[counter1].sprite);
			counter1++;
		}




		// ---------------------------------------------------------------------------------------------------------------



		// Deletes the first projectile from the array if more then 5 seconds have passed since last fire command by player.
		if (fiveSecondClock.getElapsedTime().asSeconds() >= 5) {
			if (projectileArray.size() != 0) {
				projectileDirectionsArray.erase(projectileDirectionsArray.begin());
				projectileArray.erase(projectileArray.begin());

				fiveSecondClock.restart();
			}
		}

		// Deletes first projectile from the array if we have more then 50.
		if (projectileArray.size() >= 50) {
			projectileDirectionsArray.erase(projectileDirectionsArray.begin());
			projectileArray.erase(projectileArray.begin());
		}


		if (sixSecondClock.getElapsedTime().asSeconds() >= 6) {
			sixSecondClock.restart();
		}



		// Update player
		Player1.update();

		// Flytta player
		Player1.movement();

		// Draw player
		window.draw(Player1.sprite);




		if (conversationActive == true) {
			Conversation.draw(playerX, playerY, window);
		}



		/* -------- Detta är hur medlemmar ur arrayer skulle ritas utan for-loopen.

		// Draw WoodBox1
		window.draw(WoodBox1.sprite);
		// Draw WoodBox2
		window.draw(WoodBox2.sprite);

		*/


		view.setCenter(sf::Vector2f(Player1.sprite.getPosition().x + 30, Player1.sprite.getPosition().y + 30));

		window.setView(view);
		window.display();




	}

}

