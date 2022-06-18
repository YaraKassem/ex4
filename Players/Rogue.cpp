#include "Rogue.h"

Rogue::Rogue(const std::string &m_name) : Player(m_name, "Rogue") {}

void Rogue::addCoins(int addition)
{
    if (addition > 0)
    {
        this->m_coins += 2 * addition;
    }
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.m_name, "Rogue", player.m_level, player.m_force, player.m_healthPoints, player.m_coins);
}