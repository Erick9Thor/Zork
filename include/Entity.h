#ifndef __Entity__
#define __Entity__

using namespace std;

#include <string>
#include <list>

enum class EntityType
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM,
	ENTITY,
	PLAYER
};

class Entity
{
	public:
		explicit Entity(EntityType type, string name, string description);
		virtual ~Entity();


	public:
		EntityType type;
		std::string name;
		std::string description;

		Entity* parent;
		list<Entity*> contains;

		virtual void Update();

};

#endif //__Entity__
