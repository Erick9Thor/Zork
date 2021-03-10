#include "../include/Player.h"

void Player::Talk(const string& str)
{
}

bool Player::Attack(const string& str)
{
    return false;
}

void Player::Go(const string& str)
{
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
	cout << "In this room you will find: " << endl;
	if (Show(GetLocation()->contains, EntityType::ITEM) == 0)
		cout << "No items." << endl;
	Show(GetLocation()->contains, EntityType::NPC);
}
