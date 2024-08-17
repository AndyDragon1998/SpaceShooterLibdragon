#ifndef ENTITIES
#define ENTITIES

#include <stdbool.h>

typedef struct
{
	int Health;
	int Heat;
	int X;
	int Y;
	int Speed;
	bool shoot;
	bool isAlive;

}Player;

typedef struct
{
	int X;
	int Y;
	int speed;
	bool toExplode;
	int ExplosionFrame;
	bool isAlive;
} Asteroid;

typedef struct
{
	int X;
	int Y;
	int speed;
	bool isAlive;
	
}PlayerBullet;


void initializeEntities();
void updateEntities();
void UpdateInput();
void drawEntities();
void asteroidHitCheck();
void SpawnAsteroid(int posX, int posY);
void SpawnBullet(int posX, int posY);

#endif
