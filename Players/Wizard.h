#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"
#include "../utilities.h"

class Wizard : public Player
{
    public:

    Wizard(const std::string& m_name);
    //copy c'tor assignment operator and clone

    ~Wizard() = default;

    // adds double the amount of the healAmount
    void heal(int healAmount) override;

    //decreases HP by 10 and prints
    void pitfall() override ;

    //decreases HP by 10 and prints
    void barFight() override;

    //increases HP by 20 and prints
    void fairyEncounter() override;

    void print(std::ostream& os) const override;
};

#endif