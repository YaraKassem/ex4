#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card
{
    public:

    Treasure(const std::string& name);
    ~Treasure() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;

};

#endif