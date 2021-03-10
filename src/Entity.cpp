#include "../include/Entity.h"


Entity::Entity(EntityType type, string name, string description)
{
	this->type = type;
	this->name = name;
	this->description = description;
	this->parent = nullptr;
}

Entity::~Entity()
{
}

string Entity::GetName() const
{
	return name;
}

string Entity::GetDescription() const
{
	return description;
}

EntityType Entity::GetType() const
{
	return type;
}

Entity* Entity::GetParent() const
{
	return parent;
}

void Entity::SetParent(Entity* parent)
{
	this->parent = parent;
}

void Entity::Add(Entity* entity)
{
	this->contains.push_back(entity);
}

void Entity::Remove(Entity* entity)
{
	contains.remove(entity);
}

void Entity::SeeDescription()
{
	cout << description << endl;
}
