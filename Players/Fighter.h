#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
    public:

    Fighter(const std::string& m_name);
    //copy c'tor assignment operator and clone
    ~Fighter() = default;

    // returns attack strength which is level + 2*force
    int getAttackStrength() const override;

    //decreases HP by 10 and prints
    void pitfall() override ;

    //prints
    void barFight() override;

    //prints
    void fairyEncounter() override;

    void print(std::ostream& os) const override;
};

#endif