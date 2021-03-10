#include "../include/Npc.h"

bool Npc::IsDead()
{
    return life == 0;
}

void Npc::Inspect()
{
	Entity::Inspect();
	cout << name << endl;
	
}

string Npc::GetDialogue()
{
	return dialogue;
}

void Npc::SetDialogue(string& str)
{
	this->dialogue = str;
}


void Npc::SetMonsterPosition()
{
	int pos = rand() % 4;
	switch (pos) {
	case 0:
		position = Direction::NORTH;
		break;
	case 1:
		position = Direction::EAST;
		break;
	case 2:
		position = Direction::SOUTH;
		break;
	case 3:
		position = Direction::WEST;
		break;
	}
}
