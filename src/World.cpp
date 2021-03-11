#include "../include/World.h"

World::World(string playerName)
{
	Room* wh = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");
	Room* nh = new Room("North of House", "You are facing the north side of a white house.  There is no door here, and all the windows are barred.");
	Room* bh = new Room("Behind House", "You are behind the white house.  In one corner of the house there is a small window which is slightly ajar.");

	Room* kitchen = new Room("Kitchen", "You are in the kitchen of the white house. A table seems to have been used recently for the preparation of food. A passage leads to the west and a dark staircase can be seen leading upward. A dark chimney leads down and to the east is a small window which is open.");
	Room* attic = new Room("Attic", "This is the attic. The only exit is ... fighting with this random boss!");
	Room* livingRoom = new Room("Living Room", "Above the trophy case hangs an elvish sword of great antiquity. And of course the exit if you use the key");

	//EXIT TO OTHER ROOM
	Exit* exitWhNh = new Exit("forest", ExitDescription(nh), Direction::NORTH, wh, nh);
	Exit* exitNhWh = new Exit("forest", ExitDescription(wh), Direction::SOUTH, nh, wh);

	Exit* exitNhBh = new Exit("forest", ExitDescription(bh), Direction::EAST, nh, bh);
	Exit* exitBhNh = new Exit("forest", ExitDescription(nh), Direction::NORTH, bh, nh);

	Exit* exitBhKitchen = new Exit("window", ExitDescription(kitchen), Direction::WEST, bh, kitchen);
	Exit* exitkitchenBh = new Exit("path", ExitDescription(bh), Direction::EAST, kitchen, bh);

	Exit* exitLivingRoomKitchen = new Exit("door", ExitDescription(kitchen), Direction::EAST, livingRoom, kitchen);
	Exit* exitKitchenLivingRoom = new Exit("door", ExitDescription(livingRoom), Direction::WEST, kitchen, livingRoom);
	Exit* exitKitchenAttic = new Exit("stairs", ExitDescription(attic), Direction::NORTH, kitchen, attic);
	exitKitchenAttic->SetLocked(true);
	Exit* exitAtticKitchen = new Exit("stairs", ExitDescription(kitchen), Direction::SOUTH, attic, kitchen);

	// ITEMS
	Item* key = new Item("key", "Maybe it can open something.", ItemType::KEY);
	Item* sword = new Item("sword", "A nordic sword used to kill monsters.", ItemType::WEAPON);
	Item* shield = new Item("shield", "I think this is not and shield, just a peace of wood but, maybe can works!", ItemType::SHIELD);
	Item* backpack = new Item("backpack", "A backpack, nice!, know I can save objects, I guess...", ItemType::HOLDER);


	// NPCS
	class Npc* Hugin = new class Npc("Hugin", "A crow!", "GO ATTIC!!, GO ATTIC!!", livingRoom);
	
	// MONSTER
	class Npc* Surt = new class Npc("Surt", "OMG. The king of the fire giants", "Who are you!?", attic);

	// PLAYER
	player = new Player(playerName, "You are the mighty hero of this adventure!", wh);

	// ADD Entries to WH

	wh->Add(exitWhNh);
	wh->Add(shield);

	// ADD Entries to NH

	nh->Add(exitNhWh);
	nh->Add(exitNhBh);
	nh->Add(backpack);
	nh->Add(sword);

	// ADD Entries to BH
	bh->Add(exitBhKitchen);
	bh->Add(exitBhNh);

	// ADD Entries to Kitchen
	kitchen->Add(exitkitchenBh);
	kitchen->Add(exitKitchenAttic);
	kitchen->Add(exitKitchenLivingRoom);

	// ADD Entries to Attic
	attic->Add(exitAtticKitchen);
	attic->Add(Surt);

	// AD Entries to Living Room
	livingRoom->Add(key);
	livingRoom->Add(exitBhKitchen);
	livingRoom->Add(Hugin);


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
	entities.push_back(backpack);

	entities.push_back(Hugin);
	entities.push_back(Surt);

	player->DescribeCurrentRoom();
	gameOver = false;
}

string World::ExitDescription(Room* room) {
	return "Exit to the " + room->GetName() + ".";
}

void World::ExecuteInput(const vector<string>& words)
{
	string actionName = words.at(0);
	string actionParameter = "";
	if (words.size() > 1) {
		actionParameter = words.at(1);
	}

	if (ACTION_ATTACK == actionName || ACTION_TALK == actionName) {
		actionParameter[0] = toupper(actionParameter[0]);
	}
	if (ACTION_GO == actionName) {
		player->Go(actionParameter);
	}
	else if (ACTION_ATTACK == actionName) {
		gameOver = player->Attack(actionParameter);
	}
	else if (ACTION_TALK == actionName) {
		player->Talk(actionParameter);
	}
	else if (ACTION_HELP == actionName) {
		ShowHelp();
	}
	else if (ACTION_TAKE == actionName) {
		player->Take(actionParameter);
	}
	else if (ACTION_DROP == actionName) {
		player->Drop(actionParameter);
	}
	else if (ACTION_EQUIP == actionName) {
		player->Equip(actionParameter);
	}
	else if (ACTION_UNEQUIP == actionName) {
		player->Unequip(actionParameter);
	} 
	else if (ACTION_INSPECT == actionName) {
		player->Inspect(actionParameter);
	}
	else if (ACTION_UNLOCK == actionName) {
		player->Unlock(actionParameter);
	} 
	else if (ACTION_INVENTORY == actionName) {
		player->Inventory();
	}
	else
		cerr << "Invalid action, please try again." << endl;
}

void World::ShowHelp() const
{
	cout << "Action Commands:" << endl;
	cout << ShowCommand(ACTION_GO) << " move the player to a different room. The parameter must be a direction." << endl;
	cout << ShowCommand(ACTION_ATTACK) << " attack a monster in the current room. You will need a weapon" << endl;
	cout << ShowCommand(ACTION_TALK) << " chat with an NPC." << endl;
	cout << ShowCommand(ACTION_EXIT) << " end the game." << endl;
	cout << ShowCommand(ACTION_DROP) << " drop the item from your inventory and place it in the current room." << endl;
	cout << ShowCommand(ACTION_EQUIP) << " hold that item in your hand to use it." << endl;
	cout << ShowCommand(ACTION_UNEQUIP) << " unhold that item from your hand." << endl;
	cout << ShowCommand(ACTION_INSPECT) << " describe the object you specify." << endl;
	cout << ShowCommand(ACTION_UNLOCK) << " opens an exit. You will need a key. The parameter must be a direction." << endl;
	cout << ShowCommand(ACTION_INVENTORY) << " shows all the items you have." << endl;
}

string World::ShowCommand(string str) const {
	return "- '" + str + "'";
}

World::~World()
{
	for (Entity* e : entities)
		delete e;
	entities.clear();
	delete player;
}

void World::ReadInput(const vector<string>& words)
{
	switch (words.size()) {
	case 0:
		cerr << endl;
		break;
	case 1:
	case 2:
		ExecuteInput(words);
		break;
	default:
		cerr << "ERROR: Please type 2 words max!" << endl;
		break;
	}
}

void World::SetPlayer(Player* player)
{
	player = player;
}

bool World::IsGameOver() const
{
	return gameOver;
}
