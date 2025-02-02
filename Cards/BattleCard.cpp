#include <stdbool.h>
#include "BattleCard.h"

BattleCard::BattleCard(int force, int loot, int damage, const std::string &name)
    :Card(name), m_force(force), m_loot(loot), m_damage(damage) {}
// copy c'tor = and clone

void BattleCard::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= this->m_force)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(), this->m_name);
    }

    else
    {
        player.damage(this->m_damage);
        printLossBattle(player.getName(), this->m_name);
        // what happens if player dies
    }
}

bool BattleCard::applyEncounterGang(Player &player) const
{
    if (player.getAttackStrength() >= this->m_force)
    {
        player.addCoins(this->m_loot);
        return true;
    }

    else
    {
        // player.damage(this->m_damage);
        // printLossBattle(player.getName(), this->m_name);
        this->forceDamage(player);
        return false;
    }
}

void BattleCard::forceDamage(Player &player) const
{
    player.damage(this->m_damage);
}

void BattleCard::print(std::ostream &os) const
{
    bool isDragon = false;
    if (this->m_name == "Dragon")
    {
        isDragon = true;
    }
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, isDragon);
    printEndOfCardDetails(os);
}