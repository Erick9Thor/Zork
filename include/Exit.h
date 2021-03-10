#ifndef __Exit__
#define __Exit__

#include "Entity.h"
#include "Globals.h"

class Room;

class Exit :
    public Entity
{

public:
	Exit(string name, string description, DirectionEnum direction, Room* source, Room* destination) : Entity(EntityType::EXIT, name, description) {
		this->direction = direction;
		this->source = source;
		this->destination = destination;
		this->locked = false;
	}

	DirectionEnum GetDirection() const;
	Room* GetSource() const;
	Room* GetDestination() const;

	bool IsLocked() const;
	void SetLocked(bool locked);

private:
	DirectionEnum direction;
	Room* source;
	Room* destination;
	bool locked;
};

#endif //__Exit__