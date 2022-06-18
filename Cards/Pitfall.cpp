
#include "Pitfall.h"

Pitfall::Pitfall(const std::string &name) : Card(name){}

void Pitfall::applyEncounter(Player &player) const 
{
    player.pitfall();
}


