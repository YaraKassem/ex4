#ifndef EX2_FIGHTER_H
#define EX2_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
    public:

    Fighter(const std::string& m_name);
    //copy c'tor assignment operator and clone
    ~Fighter() = default;

    // returns attack strength which is level + 2*force
    int getAttackStrength() const override;

    friend std::ostream& operator<<(std::ostream& os, const Player& player) override;
    
}

#endif