#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card
{
    public:

    //Barfight() = default;
    Barfight(const std::string& name = "");
    ~Barfight() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;
    
};

#endif