#include "../include/World.h"

World::World()
{
}

World::~World()
{
}

void World::SetPlayer(Player* player)
{
	player = player;
}

bool World::IsGameOver() const
{
	return gameOver;
}
