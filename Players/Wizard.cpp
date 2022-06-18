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

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.m_name, "Wizard", player.m_level, player.m_force, player.m_healthPoints, player.m_coins);
}