#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "BattleCard.h"
#include <vector>
#include <iostream>

class Gang : public Card
{
    std::vector<BattleCard*> m_gang;

    public:

    Gang(const std::string& name);
    ~Gang() ;
    //copy c'tor = and clone;

    void addCard(BattleCard* new_gang_member);
    
    void applyEncounter(Player &player) const override;
    
};

#endif