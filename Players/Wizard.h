#ifndef EX2_WIZARD_H
#define EX2_WIZARD_H

#include "Player.h"

class Wizard : public Player
{
    public:

    Wizard(const std::string& m_name);
    //copy c'tor assignment operator and clone

    ~Wizard() = default;

    // adds double the amount of the healAmount
    void heal(int healAmount) override;

    friend std::ostream& operator<<(std::ostream& os, const Player& player) override;
    
}

#endif