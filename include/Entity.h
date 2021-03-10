#ifndef __Entity__
#define __Entity__

using namespace std;

#include <string>
#include <list>
#include <iostream>

enum class EntityType
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM,
	ENTITY,
	PLAYER,
	NPC
};

class Entity
{
	public:
		explicit Entity(EntityType type, string name, string description);
		virtual ~Entity();

		string GetName() const;
		string GetDescription() const;
		EntityType GetType() const;
		Entity* GetParent() const;
		void SetParent(Entity* parent);

		Entity* parent;
		list<Entity*> contains;

		void Add(Entity* entity);
		void Remove(Entity* entity);

		virtual void Inspect();
		int Show(list<Entity*>& entities, EntityType type);

		virtual void SeeDescription();


	protected:
		EntityType type;
		string name;
		string description;
};

#endif //__Entity__
