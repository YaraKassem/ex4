#include "Goblin.h"
#define ATTACK_POINTS 6
#define LOOT 2
#define DAMAGE 10

Goblin::Goblin(const std::string& name) : BattleCard(ATTACK_POINTS, LOOT, DAMAGE, name){}

