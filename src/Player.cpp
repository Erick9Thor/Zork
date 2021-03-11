#include "../include/Player.h"


void Player::Talk(const string& str)
{
	class Npc* npc = GetEntityFromName<class Npc>(str, location->contains, EntityType::NPC);

	cout << npc->GetDialogue() << endl;

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
    return false;
}

void Player::Go(const string& str)
{
	Exit* exitDirection = GetExitFromDirection(str);
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
