#ifndef __Item__
#define __Item__

#include "Entity.h"

enum ItemType { COMMON, KEY, WEAPON, SHIELD, HOLDER };

class Item :
    public Entity
{
    public:
        Item(string name, string description, ItemType itemType = ItemType::COMMON) : Entity(EntityType::ITEM, name, description) {
            this->itemType = itemType;
        }

        ItemType GetItemType() const;

    private:
        ItemType itemType;
};

#endif // __Item__
