#include "Vampire.h"
#define FORCE_LOSS 1
#define ATTACK_POINTS 10
#define LOOT 2
#define DAMAGE 10

Vampire::Vampire(const std::string& name) : BattleCard(name,ATTACK_POINTS, LOOT, DAMAGE){}

 

void Vampire::applyEncounter(Player &player) const 
{
    if (player.getAttackStrength() >= this->m_loot)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(), this->m_name);
    }

    else
    {
        player.damageForce(FORCE_LOSS);
        player.damage(this->m_damage);
        printLossBattle(player.getName(), this->m_name);
    }
}

void BattleCard::forceDamage(Player &player) const
{
    player.damageForce(FORCE_LOSS);
    player.damage(this->m_damage);
    printLossBattle(player.getName(), this->m_name);
}