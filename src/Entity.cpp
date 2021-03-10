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

void Entity::Update()
{
}
