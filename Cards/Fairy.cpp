
#include "Fairy.h"

Fairy::Fairy(const std::string &name) : Card(name){}

void Fairy::applyEncounter(Player &player) const 
{
    player.fairyEncounter();
}

