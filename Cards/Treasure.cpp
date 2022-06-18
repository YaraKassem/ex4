
#include "Treasure.h"

Treasure::Treasure(const std::string &name) : Card(name){}

void Treasure::applyEncounter(Player &player) const 
{
    player.addCoins(10);
    printTreasureMessage();
}

