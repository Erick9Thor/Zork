#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"

using namespace std;

class Entity;

class World
{
public:
	World(string playerName);
	~World();

	void SetPlayer(Player* player);
	bool IsGameOver() const;
	string ExitDescription(Room* room);


	private:

		bool gameOver;
		Player* player;
		vector<Entity*> entities;
};

#endif // !__World__

