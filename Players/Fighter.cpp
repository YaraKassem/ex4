#include "Fighter.h"


Fighter::Fighter(const std::string &m_name) : Player(m_name, "Fighter") {}

int Fighter::getAttackStrength() const
{
    return ((2*this->m_force) + this->m_level);
}

void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, "Fighter", this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}

void Fighter::pitfall()
{
    this->damage(10);
    printPitfallMessage(false);
}

void Fighter::barFight() 
{
    printBarfightMessage(true);
}

    
void Fighter::fairyEncounter() 
{
    printFairyMessage(false);
}