#ifndef __World__
#define __World__

#include <string>
#include <vector>
#include <time.h>
#include "Player.h"

using namespace std;

class Entity;

class World
{
public:
	World();
	~World();

	void SetPlayer(Player* player);
	bool IsGameOver() const;

	private:

		bool gameOver;
		Player* player;
		vector<Entity*> entities;
};

#endif // !__World__

