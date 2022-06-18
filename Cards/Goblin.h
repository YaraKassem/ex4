#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "BattleCard.h"

class Goblin : public BattleCard
{
    public:

    Goblin(const std::string& name);
    ~Goblin() = default;
    //copy c'tor = and clone;

};

#endif