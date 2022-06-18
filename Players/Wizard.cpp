#include "Wizard.h"

Wizard::Wizard(const std::string &m_name) : Player(m_name, "Wizard") {}

void Wizard::heal(int healAmount)
{
    if (healAmount > 0)
    {
        this->m_healthPoints += 2 * healAmount;
        if (this->m_healthPoints > this->m_maxHP)
        {
            this->m_healthPoints = this->m_maxHP;
        }
    }
}

void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, "Wizard", this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}

void Wizard::pitfall()
{
    this->damage(10);
    printPitfallMessage(false);
    //do we need to prind end of card?
}

void Wizard::barFight() 
{
    this->damage(10);
    printBarfightMessage(false);
}

    
void Wizard::fairyEncounter() 
{
    this->heal(10);
    printFairyMessage(true);
}