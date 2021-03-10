#ifndef __Creature__
#define __Creature__


#include <string>
#include "Entity.h"
#include "Room.h"

using namespace std;

class Room;

class Creature : public Entity {

public:
	Creature(EntityType type, string name, string description, Room* location) : Entity(type, name, description) {
		this->location = location;
	}

	Room* GetLocation() const;

protected:
	Room* location;
};


#endif //__Creature__