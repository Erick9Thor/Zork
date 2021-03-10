#ifndef __Room__
#define __Room__

#include "Entity.h"

class Room : public Entity {
public:
	Room(string name, string description) : Entity(EntityType::ROOM, name, description) {}

};

#endif // !Room