#include <stdbool.h>
#include "BattleCard.h"


BattleCard::BattleCard(const std::string &name, int force, int loot, int damage)
    : Card(name), m_force(force), m_loot(loot), m_damage(damage) {}
// copy c'tor = and clone

void BattleCard::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= this->m_loot)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(), this->m_name);
    }

    else
    {
        player.damage(this->m_damage);
        printLossBattle(player.getName(), this->m_name);
        //what happens if player dies
    }
}

void BattleCard::print(std::ostream& os) const
{
    bool isDragon = false;
    if( this->m_name == "Dragon")
    {
        isDragon = true;
    }
    printMonsterDetails(os,this->m_force, this->m_damage, this->m_loot, isDragon);
    printEndOfCardDetails(os);
}