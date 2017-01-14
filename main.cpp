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
#include <fstream>
#include <string>
using namespace std;




int main() {


	string levelMatterToLoad = "levels/level1/level_matter.txt";
	string levelEnemiesToLoad = "levels/level1/level_enemies.txt";
	string levelDataToLoad = "levels/level1/level_data.txt";
	string levelTilesToLoad = "levels/level1/level_tiles.txt";
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	bool firstLoop = true;
	bool conversationActive = false;

	// Used when reading from files
	int value = 0;
	float objectXPosition = 0;
	float objectYPosition = 0;
	string objectName = " ";
	// matter
	vector<int>::const_iterator iter9;
	vector<int> sometimesWalkableArray;

	// ------------------------------------------------------------------------------------------------- Load desired level
	// Tiles are loaded inside the main loop on the first itteration


	string levelSpritesheet;
	float setPlayerStartPosX;
	float setPlayerStartPosY;
	int mapWidth;
	int sometimesWalkable;

	// --------------------------------------------------- Load data

	// initialize and open the data file
	ifstream level_data;
	level_data.open(levelDataToLoad);

	// Handle error
	if (level_data.fail()) {
		cerr << levelDataToLoad;
		exit(1);
	}

	// Set level variables
	level_data >> levelSpritesheet >> setPlayerStartPosX >> setPlayerStartPosY >> mapWidth;



	while (!level_data.eof()) {
		level_data >> sometimesWalkable;
		sometimesWalkableArray.push_back(sometimesWalkable);
	}



	




	// -------------------------------------------------------------------------------------------------------------------------



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





	sf::RenderWindow window(sf::VideoMode(1280, 800), "Gears and Brawn", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::FloatRect(0, 0, 800, 500));



	// Sätter max-framerate
	window.setFramerateLimit(100);

	


	// ------------------------------------------------------------------------------- Load and set textures
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("images/sin_spritesheet_60px.png"))
	{
		std::cout << "images/sin_spritesheet_60px.png failed to load. /n";
	}

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("images/fancySquirrel_spritesheet_60px.png"))
	{
		std::cout << "images/fancySquirrel_spritesheet_60px.png failed to load. /n";
	}

	sf::Texture snowMatterTexture;
	if (!snowMatterTexture.loadFromFile("images/snowmatter spritesheet.png"))
	{
		std::cout << "images/snowmatter spritesheet.png failed to load. /n";
	}

	sf::Texture treeWindTexture;
	if (!treeWindTexture.loadFromFile("images/treeWind_spritesheet_1260x140px.png"))
	{
		std::cout << "images/treeWind_spritesheet_1260x140px.png failed to load. /n";
	}

	sf::Texture rockProjectileTexture;
	if (!rockProjectileTexture.loadFromFile("images/rock_projectile.png"))
	{
		std::cout << "images/rock_projectile.png failed to load. /n";
	}

	sf::Texture forestTreeTexture;
	if (!forestTreeTexture.loadFromFile("images/forest_tree.png"))
	{
		std::cout << "images/forest_tree.png failed to load. /n";
	}

	sf::Texture forestTexture;
	if (!forestTexture.loadFromFile("images/forest.png"))
	{
		std::cout << "images/forest.png failed to load. /n";
	}


	sf::Texture tileTexture;
	if (!tileTexture.loadFromFile(levelSpritesheet))
	{
		std::cout << levelSpritesheet << "failed to load. /n";
	}



	// ------------------------------------------------------------------------------- 
	// ------------------------------------------------------------------------------------------------------ Define Vectors containing class objects

	// matter
	vector<matter>::const_iterator iter;
	vector<matter> matterArray;

	// world
	vector<world>::const_iterator iter8;
	vector<world> worldArray;

	// animatedmatter
	vector<animatedmatter>::const_iterator iter4;
	vector<animatedmatter> animatedmatterArray;

	// enemy
	vector<enemy>::const_iterator iter3;
	vector<enemy> enemyArray;

	// enemyHealth
	vector<int>::const_iterator iter7;
	vector<int> enemyHealthArray;

	// projectile
	vector<projectile>::const_iterator iter5;
	vector<projectile> projectileArray;

	// projectileDirections
	vector<int>::const_iterator iter6;
	vector<int> projectileDirectionsArray;

	// ------------------------------------------------------------------------------------------------------ Define objects in classes
	
	// player
	class player Player1;
	Player1.sprite.setTexture(playerTexture);

	// conversation
	class conversation Conversation;

	// matter
	// Passed to the function in order is: (Width, Height, X, Y, 1 = rectangular, 2 = circular) of the desired hitBox in relation to the sprite.
	// When circular the width is used to define the radius and height becomes superfluous.
	class matter snowMatter(80, 50, 10, 50, 1);
	class matter forestTree(120, 120, 35, 35, 1);
	class matter forest(796, 726, 0, 0, 1);
	//class matter forestTree(70, 0, 25, 30, 2);

	// world 
    class world tile(300, 300, 0, 0);

	// animatedmatter
	class animatedmatter TreeWind;

	// enemy objects
	class enemy Enemy;

	// projectile objects
	class projectile ProjectileRock;

	// ---------------------------------------------------------------------------------------------- Set sprites to textures
	Enemy.sprite.setTexture(enemyTexture);
	TreeWind.sprite.setTexture(treeWindTexture);
	ProjectileRock.sprite.setTexture(rockProjectileTexture);
	snowMatter.sprite.setTexture(snowMatterTexture);
	forestTree.sprite.setTexture(forestTreeTexture);
	forest.sprite.setTexture(forestTexture);
	tile.sprite.setTexture(tileTexture);
	// ----------------------------------------------------------------------------------------------


	// --------------------------------------------------------------------
	// Set the players starting position, variables set in level_data.txt
	Player1.setPos(setPlayerStartPosX, setPlayerStartPosY);
	// --------------------------------------------------------------------

	// Loopen som håller fönstret öppet
	while (window.isOpen())
	{


		// ------------------------------------------------------------------------------------ This is where the content of the vectors is added to the game
		if (firstLoop == true) {


			// -------------------------------------- Load matter from file
			// initialize and open the data file
			ifstream level_matter;
			level_matter.open(levelMatterToLoad);

			// Handle error
			if (level_matter.fail()) {
				cerr << levelMatterToLoad;
				exit(1);
			}
			// ---------------------------------------------

			
			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			while (!level_matter.eof()) {

				if (counter1 == 0) {
					level_matter >> objectName;
				}
				
				if (counter1 == 1){
					level_matter >> objectXPosition;
				}
				
				if (counter1 == 2) {
					level_matter >> objectYPosition;

					// All matter in the game needs to be defined here if it is to be read from the level_matter.txt file.

					if (objectName == "SnowyRock1") {

						snowMatter.sprite.setPosition(objectXPosition, objectYPosition);
						snowMatter.sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
						matterArray.push_back(snowMatter);
					}

					else if (objectName == "SnowyRock2") {

						snowMatter.sprite.setPosition(objectXPosition, objectYPosition);
						snowMatter.sprite.setTextureRect(sf::IntRect(100, 0, 100, 100));
						matterArray.push_back(snowMatter);
					}

					else if (objectName == "WindyTree1") {

						TreeWind.sprite.setPosition(objectXPosition, objectYPosition);
						TreeWind.update();
						animatedmatterArray.push_back(TreeWind);
					}

					else if (objectName == "ForestTree1") {

						forestTree.sprite.setPosition(objectXPosition, objectYPosition);
						snowMatter.sprite.setTextureRect(sf::IntRect(0, 0, 190, 190));
						matterArray.push_back(forestTree);
					}

					else if (objectName == "Forest1") {

						forest.sprite.setPosition(objectXPosition, objectYPosition);
						forest.sprite.setTextureRect(sf::IntRect(0, 0, 796, 726));
						matterArray.push_back(forest);
					}

					else {

						std::cout << "Object name on line " << counter2 - 2 << " is not defined in the while loop \n";
					}


					counter1 = 0;
					continue;
				}


				// These counters keep track of the current line so that its easy to find mistakes.
				counter1++;
				counter2++;
				counter3++;
				if (counter3 == 2) {
					counter2++;
					counter3 = 0;
				}


			}
			level_matter.close();
		
			//------------------------------------------------------------------------------------------------------------- MATTER LOAD END
			// ------------------------------------------------------------------------------------------------------------ ENEMY LOAD START


			// -------------------------------------- Load enemy from file
			// initialize and open the data file
			ifstream level_enemy;
			level_enemy.open(levelEnemiesToLoad);

			// Handle error
			if (level_enemy.fail()) {
				cerr << levelEnemiesToLoad;
				exit(1);
			}
			// ---------------------------------------------


			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			while (!level_enemy.eof()) {

				if (counter1 == 0) {
					level_enemy >> objectName;
				}

				if (counter1 == 1) {
					level_enemy >> objectXPosition;
				}

				if (counter1 == 2) {
					level_enemy >> objectYPosition;

					// All enemies in the game needs to be defined here if it is to be read from the level_enemies.txt file.

					if (objectName == "enemy1") {

						Enemy.sprite.setPosition(objectXPosition, objectYPosition);
						enemyArray.push_back(Enemy);
						enemyHealthArray.push_back(Enemy.getHealth());

					}

					else if (objectName == "enemy2") {

						Enemy.sprite.setPosition(objectXPosition, objectYPosition);
						enemyArray.push_back(Enemy);
						enemyHealthArray.push_back(Enemy.getHealth());

					}

					else {

						std::cout << "Enemy name on line " << counter2 - 2 << " is not defined in the while loop \n";
					}


					counter1 = 0;
					continue;
				}


				// These counters keep track of the current line so that its easy to find mistakes.
				counter1++;
				counter2++;
				counter3++;
				if (counter3 == 2) {
					counter2++;
					counter3 = 0;
				}


			}
			level_enemy.close();

			// ------------------------------------------------------------------------------------------------------------ ENEMY LOAD END
	








			
			// --------------------------------------------------- Load tiles from file

			// Initialize and open the tiles file
			ifstream level_tiles;
			level_tiles.open(levelTilesToLoad);

			// Handle error
			if (level_tiles.fail()) {
				cerr << levelTilesToLoad;
				exit(1);
			}



			//--------------------------------------------------------------------------------------------------------------------- Building the tiles

			// Set map array to correct tiles based on information from the level_data file.
			counter1 = 0;
			float lastValueX = 0;
			float lastValueY = 0;

			while (!level_tiles.eof())

			{
				level_tiles >> value;
				// Tiles are set to 300 x 300 px
				tile.sprite.setTextureRect(sf::IntRect(value * 300, 0, 300, 300));
				tile.sprite.setPosition(lastValueX, lastValueY);

				if (value == 9) {
					tile.setTileIsWalkable(true);
				}
				if (value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8) {
					tile.setTileIsWalkable(false);
				}

				tile.setTileNumber(value);


				worldArray.push_back(tile);


				lastValueX += 300;
				if (lastValueX >= mapWidth) {
					lastValueY += 300;
					lastValueX = 0;
				}
				counter1++;
			}

			// Close the file
			level_tiles.close();





			//----------------------------------------------------------------------------------------------------------------------------------------
	
	



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

		// --------------------------------------------------------------------------------------------------------------------------------------------------------------- FPS 
		framesPassed++;
		if (fpsClock.getElapsedTime().asSeconds() >= 1) {
			//std::cout << framesPassed << endl;
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


				//std::cout << sometimesWalkableArray[1] << endl;

			counter2 = 0;
				// We check every member of the sometimesWalkableArray, that contains the numbers of all walkable tiles provided by the data_file.
				for (iter9 = sometimesWalkableArray.begin(); iter9 != sometimesWalkableArray.end(); iter9++) {

					// This part is for changing the walkability setting on tiles from the worldArray.
					
						// If the tile number of this tile corresponds to the number of the array, we make the tile walkable.
						if (worldArray[counter1].getTileNumber() == sometimesWalkableArray[counter2]) 
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
							worldArray[counter1].setTileIsWalkable(true);

							// Was working here with getting the if statements right. ****************************************************************************************************************************************************************************************************
							} else if (Player1.hitRect.getGlobalBounds().intersects(worldArray[counter1].hitRect.getGlobalBounds()) && worldArray[counter1].tileIsWalkable() == true) {
								worldArray[counter1].setTileIsWalkable(true);
							} else {
								worldArray[counter1].setTileIsWalkable(false);
							}
						
											
					counter2++;
		    	}				


			// Get sprite position from the worldArray and draw the tile.
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
					int direction1 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[0];
					int direction2 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[1];
					int direction3 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[2];
					int direction4 = worldArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[3];
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
			matterArray[counter1].hitRect.setFillColor(sf::Color::Red);
			matterArray[counter1].hitCirc.setFillColor(sf::Color::Blue);


			matterArray[counter1].update(matterArray[counter1].sprite.getPosition().x, matterArray[counter1].sprite.getPosition().y);
			window.draw(matterArray[counter1].sprite);

			// For locating the hitbox, WORKTOOL
			//window.draw(matterArray[counter1].hitRect);
			//window.draw(matterArray[counter1].hitCirc);


			counter1++;
		}


		// Check collision with matterArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter = matterArray.begin(); iter != matterArray.end(); iter++)
		{

			// 1 = Rectangular shape
			if (matterArray[counter1].getShape() == 1) {
				if (Player1.hitRect.getGlobalBounds().intersects(matterArray[counter1].hitRect.getGlobalBounds()))
				{
					int direction1 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[0];
					int direction2 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[1];
					int direction3 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[2];
					int direction4 = matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight)[3];
					Player1.collision(direction1, direction2, direction3, direction4);
				}
			}


			// 2 = Circular shape
			if (matterArray[counter1].getShape() == 2) {
				if (Player1.hitRect.getGlobalBounds().intersects(matterArray[counter1].hitCirc.getGlobalBounds()))
				{

					// Collision detection with circle does not exist yet.
					
					/*
					int direction1 = 1;
					int direction2 = 0;
					int direction3 = 0;
					int direction4 = 0;

					Player1.collision(direction1, direction2, direction3, direction4);
					*/
				}
			}

			// Check if player is colliding with objects from the matterArray.


			counter2 = 0;
			// Cycle through the projectileArray for each piece of matter.
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

		// Use jetpack with Lshift
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			Player1.specialMovement(1);
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

