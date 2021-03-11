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



#define ACTION_GO "go"

#define ACTION_ATTACK "attack"

#define ACTION_TALK "talk" 

#define ACTION_EXIT "exit"

#define ACTION_HELP "help"

class World
{
public:
	World(string playerName);
	~World();

	void ReadInput(const vector<string>& words);

	void SetPlayer(Player* player);
	bool IsGameOver() const;
	string ExitDescription(Room* room);


	private:
		void ExecuteInput(const vector<string>& words);

		void ShowHelp() const;
		string ShowCommand(string str) const;

		bool gameOver;
		Player* player;
		vector<Entity*> entities;
};

#endif // !__World__

