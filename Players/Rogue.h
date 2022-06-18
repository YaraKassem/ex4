#ifndef EX2_ROGUE_H
#define EX2_ROGUE_H

#include "Player.h" 

class Rogue : public Player
{
    public:

    Rogue(const std::string& m_name);
    //copy c'tor assignment operator and clone

    ~Rogue() = default;

    // adds double the amount of the coins
    void addCoins(int addition) override;

    friend std::ostream& operator<<(std::ostream& os, const Player& player) override;
    
}

#endif




