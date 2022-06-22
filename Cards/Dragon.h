#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard
{
    public:
    Dragon() = default;
    Dragon(const std::string& name);
    ~Dragon() = default;
    //copy c'tor = and clone
};

#endif