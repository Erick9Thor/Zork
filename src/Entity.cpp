#include "../include/Entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = EntityType::ENTITY;

	if (parent != NULL) {
		parent->contains.push_back(this);
	}
}

Entity::~Entity()
{
}

void Entity::Update()
{
}
