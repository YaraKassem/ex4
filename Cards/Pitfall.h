#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card
{
    public:
    Pitfall() = default;
    Pitfall(const std::string& name);
    ~Pitfall() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;

};

#endif