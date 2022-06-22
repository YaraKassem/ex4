#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "BattleCard.h"

class Vampire : public BattleCard
{
    public:
    Vampire() = default;
    Vampire(const std::string& name);
    ~Vampire() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;

    //forces loss
    void forceDamage(Player &player) const override;
};

#endif