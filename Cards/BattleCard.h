#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include <string>
#include "Card.h"
#include "../utilities.h"

class BattleCard : public Card
{
    protected:

    int m_force;
    int m_loot;
    int m_damage;

    public:
    //BattleCard() = default;
    BattleCard(int force, int loot, int damage, const std::string& name = "");
    virtual ~BattleCard() = default;
    //copy c'tor = and clone
    virtual void applyEncounter(Player &player) const override;
    virtual bool applyEncounterGang(Player &player) const;
    virtual void forceDamage(Player &player) const;
    void print(std::ostream& os) const;
};

#endif

