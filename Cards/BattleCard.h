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

    BattleCard(const std::string& name, int force, int loot, int damage);
    virtual ~BattleCard() = default;
    //copy c'tor = and clone
    virtual void applyEncounter(Player &player) const override;
    void print(std::ostream& os) const;
};

#endif

