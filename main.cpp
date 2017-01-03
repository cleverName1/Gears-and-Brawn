#include <iostream>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "enemy.h"
#include "matter.h"
#include "animatedmatter.h"
#include "tile.h"
#include "projectile.h"
#include <vector>
using namespace std;





int main() {



	// Used to limit firing speed
	sf::Clock oneSecondClock;

	// Used to limit damage dealt.
	sf::Clock oneSecondClockTwo;

	// Used to control enemy Movement
	sf::Clock sixSecondClock;

	// Used to erase projectiles
	sf::Clock fiveSecondClock;

	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	bool firstLoop = true;




	sf::RenderWindow window(sf::VideoMode(1280, 800), "Gears and Brawn", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::FloatRect(0, 0, 800, 500));





	// Sätter max-framerate
	window.setFramerateLimit(100);


	// ------------------------------------------------------------------------------- Laddar och sätter texturer
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


	sf::Texture woodBoxTexture;
	if (!woodBoxTexture.loadFromFile("woodBox.png"))
	{
		std::cout << "woodBox.png failed to load. /n";
	}

	sf::Texture stoneWallTexture;
	if (!stoneWallTexture.loadFromFile("stoneWall.png"))
	{
		std::cout << "stoneWall.png failed to load. /n";
	}

	sf::Texture stoneWallTextureVertical;
	if (!stoneWallTextureVertical.loadFromFile("stoneWall_vertical.png"))
	{
		std::cout << "stoneWall_vertical.png failed to load. /n";
	}

	sf::Texture grassTexture;
	if (!grassTexture.loadFromFile("grass1.png"))
	{
		std::cout << "grass1.png failed to load. /n";
	}

	sf::Texture waterTexture;
	if (!waterTexture.loadFromFile("water2.png"))
	{
		std::cout << "water1.png failed to load. /n";
	}

	sf::Texture waterEdgeUpTexture;
	if (!waterEdgeUpTexture.loadFromFile("wateredgeup1.png"))
	{
		std::cout << "wateredgeup1.png failed to load. /n";
	}

	sf::Texture bottomBorderTexture;
	if (!bottomBorderTexture.loadFromFile("bottomImageBranches.png"))
	{
		std::cout << "bottomImageBranches.png failed to load. /n";
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



	// ------------------------------------------------------------------------------- 

	class player Player1;
	Player1.sprite.setTexture(playerTexture);


	// matter array
	vector<matter>::const_iterator iter;
	vector<matter> matterArray;

	// matter objects
	class matter WoodBox;
	class matter StoneWall;
	class matter StoneWallVertical;
	class matter Water;
	class matter WaterEdgeUp;
	class matter BottomImage;

	// animatedmatter array
	vector<animatedmatter>::const_iterator iter4;
	vector<animatedmatter> animatedmatterArray;

	// animatedmatter objects

	class animatedmatter TreeWind;

	// tile array
	vector<tile>::const_iterator iter2;
	vector<tile> tileArray;

	// tile objects
	class tile Grass;

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


	WoodBox.sprite.setTexture(woodBoxTexture);
	StoneWall.sprite.setTexture(stoneWallTexture);
	StoneWallVertical.sprite.setTexture(stoneWallTextureVertical);
	Grass.sprite.setTexture(grassTexture);
	Water.sprite.setTexture(waterTexture);
	WaterEdgeUp.sprite.setTexture(waterEdgeUpTexture);
	BottomImage.sprite.setTexture(bottomBorderTexture);
	Enemy.sprite.setTexture(enemyTexture);
	TreeWind.sprite.setTexture(treeWindTexture);
	ProjectileRock.sprite.setTexture(rockProjectileTexture);



	// Loopen som håller fönstret öppet
	while (window.isOpen())
	{


		// ----------------------------------------------------------------------------------------------------------- This is where matters are added to the game
		if (firstLoop == true) {


			//WoodBox.sprite.setPosition(300, 340);
			//matterArray.push_back(WoodBox);


			Enemy.sprite.setPosition(25, 85);
			enemyArray.push_back(Enemy);
			enemyHealthArray.push_back(Enemy.getHealth());

			TreeWind.sprite.setPosition(0, 0);
			TreeWind.update();
			animatedmatterArray.push_back(TreeWind);


			/*
			StoneWall.sprite.setPosition(0, 0);
			matterArray.push_back(StoneWall);
			StoneWall.sprite.setPosition(480, 0);
			matterArray.push_back(StoneWall);
			StoneWall.sprite.setPosition(940, 0);
			matterArray.push_back(StoneWall);


			StoneWall.sprite.setPosition(0, 740);
			matterArray.push_back(StoneWall);
			StoneWall.sprite.setPosition(480, 740);
			matterArray.push_back(StoneWall);
			StoneWall.sprite.setPosition(940, 740);
			matterArray.push_back(StoneWall);



			StoneWallVertical.sprite.setPosition(0, 60);
			matterArray.push_back(StoneWallVertical);
			StoneWallVertical.sprite.setPosition(0, 540);
			matterArray.push_back(StoneWallVertical);
			StoneWallVertical.sprite.setPosition(1220, 60);
			matterArray.push_back(StoneWallVertical);
			StoneWallVertical.sprite.setPosition(1220, 540);
			matterArray.push_back(StoneWallVertical);
			*/

			// Testar att skapa en stenprojektil i världen
			//ProjectileRock.sprite.setPosition(420, 540);
			//projectileArray.push_back(ProjectileRock);


			//BottomImage.sprite.setPosition(0, 740);
			//matterArray.push_back(BottomImage);


			// Variables for for-loop drawing
			int lastValueX;
			int lastValueY;


			/*
			// Paints water
			int lastValueX = 690;
			int lastValueY = 300;
			bool firstRow = true;
			for (int i = 0; i != 32; i++)
			{

			if (firstRow == true) {
			WaterEdgeUp.sprite.setPosition(lastValueX, lastValueY);
			matterArray.push_back(WaterEdgeUp);
			}
			else {
			Water.sprite.setPosition(lastValueX, lastValueY);
			matterArray.push_back(Water);

			}

			lastValueX += 30;
			if (lastValueX == 900) {
			lastValueY += 30;
			lastValueX = 600;
			firstRow = false;
			}
			}
			*/

			// Paint grass
			lastValueX = -900;
			lastValueY = -1200;
			for (int i = 0; i != 6499; i++)
			{

				Grass.sprite.setPosition(lastValueX, lastValueY);
				tileArray.push_back(Grass);
				lastValueX += 30;
				if (lastValueX >= 1100) {
					lastValueY += 30;
					lastValueX = -900;
				}
			}






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


		float playerWidth = Player1.sprite.getGlobalBounds().width;
		float playerHeight = Player1.sprite.getGlobalBounds().height;
		float playerX = Player1.sprite.getPosition().x;
		float playerY = Player1.sprite.getPosition().y;



		// Create box with space
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



		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION tile
		// Draw tile to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter2 = tileArray.begin(); iter2 != tileArray.end(); iter2++)
		{

			window.draw(tileArray[counter1].sprite);
			counter1++;
		}


		/*
		// Check collision with tileArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter2 = tileArray.begin(); iter2 != tileArray.end(); iter2++)
		{

		if (Player1.sprite.getGlobalBounds().intersects(tileArray[counter1].sprite.getGlobalBounds()))
		{
		std::cout << "Colliding with tile\n";
		Player1.collision(tileArray[counter1].collision(playerX, playerY, playerWidth, playerHeight));
		}
		counter1++;
		}

		*/
		// ---------------------------------------------------------------------------------------------------------------


		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION matter
		// Draw matter to the screen, iter is set to the begining of the array
		counter1 = 0;
		for (iter = matterArray.begin(); iter != matterArray.end(); iter++)
		{

			window.draw(matterArray[counter1].sprite);
			counter1++;
		}


		// Check collision with matterArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter = matterArray.begin(); iter != matterArray.end(); iter++)
		{

			if (Player1.sprite.getGlobalBounds().intersects(matterArray[counter1].sprite.getGlobalBounds()))
			{
				Player1.collision(matterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight));
			}
			counter1++;
		}

		// ---------------------------------------------------------------------------------------------------------------



		// -------------------------------------------------------------------------------------------------------------- DRAW + COLLISION enemy
		
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
				enemyArray[counter1].sprite.setColor(sf::Color(255, 255, 255, 255));
				counter2 = 0;

				// Cycle through the projectileArray for each enemy.
				for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
				{
					// If a member of projectileArray intersects a member of enemyArray
					if (projectileArray[counter2].sprite.getGlobalBounds().intersects(enemyArray[counter1].sprite.getGlobalBounds()))
					{


						for (iter7 = enemyHealthArray.begin(); iter7 != enemyHealthArray.end(); iter7++)
						{

							// See if the enemy has any health left, execute code to reduce health or for hitting a corpse.
							if (enemyHealthArray[counter1] <= 0) {
			
								// If the Projectile is moving, it hit a dead target.
								if (projectileDirectionsArray.at(counter2) != 5) {
									// If Projectile hits target, set its movement direction to 5, which represents no direciton, stopping it.
									projectileDirectionsArray.at(counter2) = 5;
									std::cout << "Dead!\n";
									enemyArray[counter1].sprite.setColor(sf::Color::Red);
									enemyArray[counter1].sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));

								}
								

							}
							else {
								// If enemy is not dead, deal damage
								if (oneSecondClockTwo.getElapsedTime().asSeconds() >= 1) {
									
									
									// If the Projectile is moving, deal damage.
									if (projectileDirectionsArray.at(counter2) != 5) {
										// If Projectile hits target, set its movement direction to 5, which represents no direciton, stopping it.
										projectileDirectionsArray.at(counter2) = 5;
										enemyHealthArray.at(counter1) -= 2;
										std::cout << enemyHealthArray[counter1] << endl;
										enemyArray[counter1].sprite.setColor(sf::Color::Red);

										// If the shoot kills the enemy, set appropriate texture.
										if (enemyHealthArray[counter1] <= 0) {
											enemyArray[counter1].sprite.setTextureRect(sf::IntRect(0, 60, 60, 60));
										}

									}
									oneSecondClockTwo.restart();
								}								
							}
						}
					}
					counter2++;
				}
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

			if (Player1.sprite.getGlobalBounds().intersects(animatedmatterArray[counter1].sprite.getGlobalBounds()))
			{
				Player1.collision(animatedmatterArray[counter1].collision(playerX, playerY, playerWidth, playerHeight));
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


		// Check collision with matterArray, iter is set to the begining of the array
		counter1 = 0;
		for (iter5 = projectileArray.begin(); iter5 != projectileArray.end(); iter5++)
		{

			if (Player1.sprite.getGlobalBounds().intersects(projectileArray[counter1].sprite.getGlobalBounds()))
			{
				Player1.collision(projectileArray[counter1].collision(playerX, playerY, playerWidth, playerHeight));
			}
			counter1++;
		}

		// ---------------------------------------------------------------------------------------------------------------


		/* ------ Detta är hur collision skulle kollas utan for-loopen
		if (Player1.sprite.getGlobalBounds().intersects(WoodBox1.sprite.getGlobalBounds()))
		{
		Player1.collision(WoodBox1.collision(playerX, playerY, playerWidth, playerHeight));
		}

		*/


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