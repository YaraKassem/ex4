#include "Fighter.h"


Fighter::Fighter(const std::string &m_name) : Player(m_name, "Fighter") {}


int Fighter::getAttackStrength() const
{
    return ((2*this->m_force) + this->m_level);
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.m_name, "Fighter", player.m_level, player.m_force, player.m_healthPoints, player.m_coins);
}