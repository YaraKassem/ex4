#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h" 

class Rogue : public Player
{
    public:

    Rogue(const std::string& m_name);
    //copy c'tor assignment operator and clone

    ~Rogue() = default;

    // adds double the amount of the coins
    void addCoins(int addition) override;

    //only prints
    void pitfall() override ;

    //decreases HP by 10 and prints
    void barFight() override;

    //prints
    void fairyEncounter() override;

    void print(std::ostream& os) const override;
    
};

#endif




