#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Npc.h"
#include "Exit.h"
#include "Globals.h"
#include "Item.h"

class Player :
    public Creature
{
    public:
		Player(string name, string description, Room* location) : Creature(EntityType::PLAYER, name, description, location) {
			this->holdingRightItem = nullptr;
			this->holdingLeftItem = nullptr;
		}

        // PLAYER ACTIONS
		void Go(const string& str);
		void Talk(const string& str);
		bool Attack(const string& str);
		void Take(const string& str);
		void Equip(const string& str);
		void Unequip(const string& str);
		void Drop(const string& str);
		void Unlock(const string& str);
		void Inspect(const string& str);

		void Inventory();
		void DescribeCurrentRoom();

		Item* GetHoldingRightItem() const;
		Item* GetHoldingLeftItem() const;

		void SetHoldingItem(Item* item);

	private:

		Exit* GetExitFromDirection(const string& str) const;
		Exit* GetExitFromDirection(const Direction& dir) const;

		template <class T>
		T* GetEntityFromName(const string& name, const list<Entity*>& entities, const EntityType type) const;


		Item* GetItemFromType(ItemType type) const;
			
		Item* holdingRightItem;
		Item* holdingLeftItem;
};


#endif // !Player