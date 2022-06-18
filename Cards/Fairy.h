#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card
{
    public:

    Fairy(const std::string& name);
    ~Fairy() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;
    
};

#endif