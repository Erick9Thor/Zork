#ifndef __Npc__
#define __Npc__

#include "Creature.h"
#include "Globals.h"

const int baseNpcLife = 5;

class Npc :
    public Creature
{
    public:
        Npc(string name, string description, Room* location) : Creature(EntityType::NPC, name, description, location) {
            this->life = baseNpcLife;
            SetMonsterPosition();
        }

        void Attack();
        bool IsDead();

    private:
        void SetMonsterPosition();

        Direction position;
        int life;
};

#endif // !Npc



