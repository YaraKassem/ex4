#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card
{
    public:
    Merchant() = default;
    Merchant(const std::string& name);
    ~Merchant() = default;
    //copy c'tor = and clone;
    
    void applyEncounter(Player &player) const override;
    
};

#endif