#ifndef __Npc__
#define __Npc__

#include "Creature.h"
#include "Globals.h"

const int baseNpcLife = 5;

class Npc :
    public Creature
{
    public:
        Npc(string name, string description, string dialogue, Room* location) : Creature(EntityType::NPC, name, description, location) {
            this->dialogue = dialogue;
            this->life = baseNpcLife;
            SetMonsterPosition();
        }

        void Attack();
        bool IsDead();

        void Inspect();

        string GetDialogue();
        void SetDialogue(string& str);

    private:
        void SetMonsterPosition();
        
        string dialogue;
        Direction position;
        int life;
};

#endif // !Npc



