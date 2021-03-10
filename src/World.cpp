#include "../include/World.h"

World::World(string playerName)
{
	// LivingRoom
	Room* wh = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");
	Room* nh = new Room("North of House", "You are facing the north side of a white house.  There is no door here, and all the windows are barred.");
	Room* bh = new Room("Behind House", "You are behind the white house.  In one corner of the house there is a small window which is slightly ajar.");

	Room* kitchen = new Room("Kitchen", "You are in the kitchen of the white house. A table seems to have been used recently for the preparation of food. A passage leads to the west and a dark staircase can be seen leading upward. A dark chimney leads down and to the east is a small window which is open.");
	Room* attic = new Room("Attic", "This is the attic. The only exit is ... fighting with this random boss!");
	Room* livingRoom = new Room("Living Room", "Above the trophy case hangs an elvish sword of great antiquity. And of course the exit if you use the key");

	//EXIT TO OTHER ROOM
	Exit* exitWhNh = new Exit("path", ExitDescription(nh), Direction::NORTH, wh, nh);
	Exit* exitNhWh = new Exit("path", ExitDescription(wh), Direction::SOUTH, nh, wh);

	Exit* exitNhBh = new Exit("path", ExitDescription(bh), Direction::EAST, nh, bh);
	Exit* exitBhNh = new Exit("path", ExitDescription(nh), Direction::NORTH, bh, nh);

	Exit* exitBhKitchen = new Exit("window", ExitDescription(kitchen), Direction::WEST, bh, kitchen);
	Exit* exitkitchenBh = new Exit("path", ExitDescription(bh), Direction::EAST, kitchen, bh);

	Exit* exitLivingRoomKitchen = new Exit("door", ExitDescription(kitchen), Direction::EAST, livingRoom, kitchen);
	Exit* exitKitchenLivingRoom = new Exit("door", ExitDescription(livingRoom), Direction::WEST, kitchen, livingRoom);
	Exit* exitKitchenAttic = new Exit("stairs", ExitDescription(attic), Direction::NORTH, kitchen, attic);
	Exit* exitAtticKitchen = new Exit("stairs", ExitDescription(kitchen), Direction::SOUTH, attic, kitchen);

	// ITEMS
	Item* key = new Item("key", "Maybe it can open something.", ItemType::KEY);
	Item* sword = new Item("sword", "A nordic sword used to kill monsters.", ItemType::WEAPON);
	Item* shield = new Item("shield", "I think this is not and shield, just a peace of wood", ItemType::WEAPON);

	// NPCS
	class Npc* Hugin = new class Npc("Hugin", "A crow!", "GO ATTIC!!, GO ATTIC!!", kitchen);
	

	// MONSTER
	class Npc* Surtur = new class Npc("Surtur", "OMG. The king of the fire giants", "He wants to start the Ragnarock!", attic);

	// PLAYER
	player = new Player(playerName, "You are the mighty hero of this adventure!", wh);

	// ADD ENTITIES TO THE WORD
	entities.push_back(wh);
	entities.push_back(nh);
	entities.push_back(bh);

	entities.push_back(kitchen);
	entities.push_back(attic);
	entities.push_back(livingRoom);

	entities.push_back(exitWhNh);
	entities.push_back(exitNhWh);
	entities.push_back(exitNhBh);
	entities.push_back(exitBhNh);
	entities.push_back(exitBhKitchen);
	entities.push_back(exitkitchenBh);
	entities.push_back(exitLivingRoomKitchen);
	entities.push_back(exitKitchenLivingRoom);
	entities.push_back(exitKitchenAttic);
	entities.push_back(exitAtticKitchen);

	entities.push_back(key);
	entities.push_back(sword);
	entities.push_back(shield);

	entities.push_back(Hugin);
	entities.push_back(Surtur);

	player->DescribeCurrentRoom();
	gameOver = false;
}

string World::ExitDescription(Room* room) {
	return "Exit to the " + room->GetName() + ".";
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
