#include "Gang.h"

Gang::Gang(const std::string &name) : Card(name) {}

Gang::~Gang()
{
    int size = this->m_gang.size();
    for (int i = 0; i < size; i++)
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
    int i = 0;
    int size = this->m_gang.size();
    for (; i < size; i++)
    {
        if (this->m_gang[i]->applyEncounterGang(player) == false)
        {
            printLossBattle(player.getName(), m_gang[i]->getName());
            i++;
            for (; i < size; i++)
            {
                printLossBattle(player.getName(), m_gang[i]->getName());
                this->m_gang[i]->forceDamage(player);
            }
            return;
        }
    }
    printWinBattle(player.getName(), "Gang");
    player.levelUp();
}