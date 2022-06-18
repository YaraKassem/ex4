#include "Rogue.h"

Rogue::Rogue(const std::string &m_name) : Player(m_name, "Rogue") {}

void Rogue::addCoins(int addition)
{
    if (addition > 0)
    {
        this->m_coins += 2 * addition;
    }
}

void Rogue::print(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, "Rogue", this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}

void Rogue::pitfall()
{
    printPitfallMessage(true);
}

void Rogue::barFight() 
{
    this->damage(10);
    printBarfightMessage(false);
}

    
void Rogue::fairyEncounter() 
{
    printFairyMessage(false);
}