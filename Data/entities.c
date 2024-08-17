/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : All the entities that do stuff on game field		     */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : entities.c	                                             */
/*                                                                           */
/*****************************************************************************/

#include "include/entities.h"

#include "include/input.h"
#include <libdragon.h>

#include "extern/input.ext"


PlayerBullet bulletArray[20];
Asteroid asteroidArray[50];
Player player;

sprite_t* playerSprite;
sprite_t* asteroidSprite;
sprite_t* bulletSprite;

int MAX_BULLET_COUNT = 20;
int currentBulletCount = 0;
int asteroidLaunchTimer = 0;
int currentAsteroidCount = 0;
int AsteroidRate = 30;

extern bool GameOverBoolean;

void initializeEntities()
{

	playerSprite = sprite_load("rom:/Graphics/Sprites/player.sprite");
	asteroidSprite = sprite_load("rom:/Graphics/Sprites/asteroid.sprite");
	bulletSprite = sprite_load("rom:/Graphics/Sprites/bullet.sprite");

	player.X = 320;
	player.Y = 380;
	player.Speed = 3;
	player.Health = 30;
	player.Heat = 0;
	player.isAlive = true;
}

void updateEntities()
{
	asteroidHitCheck();
	
	if(!player.isAlive)
	{
		GameOverBoolean = true;
	}
	
	if(asteroidLaunchTimer > AsteroidRate)
	{
		int x = rand();
		x = x % 600;
		SpawnAsteroid((float)x, -15.0f);
		asteroidLaunchTimer = 0;
	}
	asteroidLaunchTimer++;

	// This part here makes sure that player is in bounds of the screen
	if(player.X < 0.0f)
	{
		player.X = 0.0f;
	}
	
	if(player.X > 640.0f- playerSprite->width)
	{
		player.X = 640.0f - playerSprite->width;
	}
	
	if(player.Y < 0.0f + playerSprite->height)
	{
		player.Y = playerSprite->height;
	}
	
	if(player.Y > 512.0f - playerSprite->height)
	{
		player.Y = 512.0f - playerSprite->height;
	}

	
	if(player.shoot)
	{
		//PlaySoundEffect(&Shoot, BulletChannels);
		
		// This part here ensures that each bullet shoot uses it's own sound channel which cycles from 0 to 3
		//BulletChannels++;
		
		/*if(BulletChannels > 3)
		{
			BulletChannels = 0;
		}*/
		SpawnBullet(player.X + playerSprite->width / 2, player.Y + playerSprite->height / 2);
	}
	
	// This segment here updates the Asteroids movement, and removes them in case
	// the asteroid has reached end of the screen or has hit something.
	for(int i = 0; i < currentAsteroidCount; i++)
	{
		asteroidArray[i].Y+= asteroidArray[i].speed;
		
		if(asteroidArray[i].Y > 512.0f || !asteroidArray[i].isAlive)
		{
			for (int j = i; j < currentAsteroidCount; j++)  
			{  
			    asteroidArray[j] = asteroidArray[j+1]; 
			}  
			currentAsteroidCount--;
		}
	}
	
	// This segment updates the bullet position on the screen 
	for(int i = 0; i < currentBulletCount; i++)
	{
		bulletArray[i].Y-= bulletArray[i].speed;
		//printf("Bullet Position X = %.2f Y = %.2f \n", bulletArray[i].X, bulletArray[i].Y);
		if( bulletArray[i].Y < -10.0f || !bulletArray[i].isAlive)
		{		
			for (int j = i; j < currentBulletCount; j++)  
			{  
			    bulletArray[j] = bulletArray[j+1]; 
			}  
			currentBulletCount--;
		}
	}
}

// This part here handles the input for player Ship
void UpdateInput()
{
	if(pad1.inputUp == 1)
	{
		player.Y -= player.Speed;
	}
	
	if(pad1.inputDown == 1)
	{
		player.Y += player.Speed;
	}
			
	if(pad1.inputLeft == 1)
	{
		player.X -= player.Speed;
	}
			
	if(pad1.inputRight == 1)
	{
		player.X += player.Speed;
	}
			
	// if Button pressed shoot equals true
	player.shoot = pad1.inputB;
	
	
}

void drawEntities()
{


	rdpq_sprite_blit(playerSprite,player.X,player.Y,NULL);

	// Loop for drawing Asteroids
	for(int i = 0; i < currentAsteroidCount; i++)
	{
		rdpq_sprite_blit(asteroidSprite,asteroidArray[i].X,asteroidArray[i].Y,NULL);
	}
	// Loop for drawing player Bullets
	for(int i = 0; i < currentAsteroidCount; i++)
	{
		rdpq_sprite_blit(bulletSprite,bulletArray[i].X,bulletArray[i].Y,NULL);
	}
}

// This function checks if asteroid has been hit by the player Bullet
void asteroidHitCheck()
{
	for(int j = 0; j < currentBulletCount; j++)
	{
		for(int i = 0; i < currentAsteroidCount; i++)
		{
			
			if(bulletArray[j].X > asteroidArray[i].X && bulletArray[j].X < asteroidArray[i].X + asteroidSprite->width)
			{
			    if((bulletArray[j].Y > asteroidArray[i].Y && bulletArray[j].Y < asteroidArray[i].Y + asteroidSprite->height)&& !asteroidArray[i].toExplode) 
			    {
				    	//asteroidArray[i].toExplode = true;
				    	bulletArray[j].isAlive = false;
				    	asteroidArray[i].isAlive = false;
				    	/*PlaySoundEffect2(&ExplosionSE, ExplosionChannels);			
				    	// This is same as with bullet Sound Effect channels
				    	ExplosionChannels++;
				    	if(ExplosionChannels > 7)
				    	{
				    		ExplosionChannels = 4;
				    	}*/
			    }
			    else
			    {

			    }
			
			}
			else
			{

			}
		}
	
	}
	
	for(int i = 0; i < currentAsteroidCount; i++)
		{
			
			if(player.X > asteroidArray[i].X && player.X < asteroidArray[i].X + asteroidSprite->width)
			{
			    if(player.Y > asteroidArray[i].Y && player.Y < asteroidArray[i].Y + asteroidSprite->height)
			    {
			    		asteroidArray[i].isAlive = false;
			    		//player.Health -=1;
			    		player.isAlive = false;
			    }
			    else
			    {
			    
			    }
			
			}
			else
			{

			}
		}
}


// Spawns Asteroid at X, Y coordinates, provided below
void SpawnAsteroid(int posX, int posY)
{
	asteroidArray[currentAsteroidCount].X = posX;
	asteroidArray[currentAsteroidCount].Y = posY;
	asteroidArray[currentAsteroidCount].speed = 3.0f;
	asteroidArray[currentAsteroidCount].isAlive = true;
	currentAsteroidCount++;
	asteroidArray[currentAsteroidCount].ExplosionFrame = 0;
}

// Spawns Bullet at X, Y coordinates, based on player position
void SpawnBullet(int posX, int posY)
{
	bulletArray[currentBulletCount].X = posX;
	bulletArray[currentBulletCount].Y = posY;
	bulletArray[currentBulletCount].speed = 8.0f;
	bulletArray[currentBulletCount].isAlive = true;
	currentBulletCount++;
}
