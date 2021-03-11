#include "../include/Player.h"


void Player::Talk(const string& str)
{
	class Npc* npc = GetEntityFromName<class Npc>(str, location->contains, EntityType::NPC);

	if (npc == nullptr) {
		cout << "You can't talk to " << str << "." << endl;
	}
	else {
		cout << npc->GetDialogue() << endl;
	}
}

template <class T>
T* Player::GetEntityFromName(const string& name, const list<Entity*>& entities, const EntityType type) const {
	T* entity = nullptr;

	// Search for entities
	for (Entity* e : entities) {

		if (e->GetType() == type) {

			string entityName = e->GetName();
			if (entityName == name) {
				entity = (T*)e;
				break;
			}
		}
	}

	return entity;
}

bool Player::Attack(const string& str)
{
	bool gameOver = false;

	class Npc* npcToKill = GetEntityFromName<class Npc>(str, location->contains, EntityType::NPC);

	if (npcToKill == nullptr) {
		cout << "Nothing to attack in this room." << endl;
	}
	else {

		Item* weapon = GetItemFromType(ItemType::WEAPON);

		if (weapon == nullptr) {
			cout << "You don't have a weapon to attack." << endl;
		}
		else {
			if (weapon == GetHoldingItem()) {
				npcToKill->Attack();
				if (npcToKill->IsDead()) {
					cout << "CONGRATULATIONS! YOU BEAT THE GAME!" << endl;
					gameOver = true;
				}
			}
			else
				cout << "You need to equip a weapon to attack." << endl;
		}
	}
    
	return gameOver;
}

Item* Player::GetHoldingItem() const {
	return holdingItem;
}

void Player::SetHoldingItem(Item* item)
{
	holdingItem = item;
}

Item* Player::GetItemFromType(ItemType type) const
{
	Item* item = nullptr;

	for (Entity* entity : contains) {
		if (entity->GetType() == EntityType::ITEM && ((Item*)entity)->GetItemType() == type) {
			item = (Item*)entity;
			break;
		}
	}

	return item;
}

void Player::Go(const string& str)
{
	bool moved = false;

	Exit* exit = GetExitFromDirection(str);
	if (exit != nullptr) {
		if (exit->IsLocked()) {
			cout << str << " is locked." << endl;
		}
		else {
			cout << "Walking to " << str << "..." << endl;
			location = exit->GetDestination();
			DescribeCurrentRoom();
			moved = true;
		}
	}

	if (!moved)
		cout << "You can't go to " << str << "." << endl;
}

Exit* Player::GetExitFromDirection(const string& str) const {
	return Globals::isDir(str) ? GetExitFromDirection(*Globals::strToDir(str)) : nullptr;
}

Exit* Player::GetExitFromDirection(const Direction& dir) const
{
	Exit* exit = nullptr;

	for (Entity* e : location->contains) {

		if (e->GetType() == EntityType::EXIT) {
			if (dir == ((Exit*)e)->GetDirection()) {
				exit = (Exit*)e;
				break;
			}
		}
	}

	return exit;
}


void Player::Inspect(const string& str)
{
}

void Player::Take(const string& str)
{
}

void Player::Equip(const string& str)
{
}

void Player::Drop(const string& str)
{
}

void Player::Unequip(const string& str)
{
}

void Player::Unlock(const string& str)
{
}

void Player::Loot(const string& str)
{
}

void Player::DescribeCurrentRoom()
{
	cout << "You are now in the " << location->GetName() << "." << endl;
	GetLocation()->Inspect();
	cout << "You will find: " << endl;
	if (Show(GetLocation()->contains, EntityType::ITEM) == 0)
		cout << "No items." << endl;
	Show(GetLocation()->contains, EntityType::NPC);
}
