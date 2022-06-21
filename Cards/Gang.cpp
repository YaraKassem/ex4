#include "Gang.h"

Gang::Gang(const std::string &name) : Card(name) {}

Gang::~Gang()
{
    for (int i = 0; i < this->m_gang.size(); i++)
    {
       delete this->m_gang[i];
    }
}

void Gang::addCard(BattleCard *new_gang_member)
{
    this->m_gang.push_back(new_gang_member);
}

void Gang::applyEncounter(Player &player) const
{
    for (int i = 0; i < this->m_gang.size(); i++)
    {
        if (this->m_gang[i]->applyEncounterGang(player) == false)
        {
            i++;
            for (i; i < this->m_gang.size(); i++)
            {
                this->m_gang[i]->forceDamage(player);
            }
            return;
        }
    }
}