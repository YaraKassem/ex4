
#include "Barfight.h"

Barfight::Barfight(const std::string &name) : Card(name){}

void Barfight::applyEncounter(Player &player) const 
{
    player.barFight();
}

