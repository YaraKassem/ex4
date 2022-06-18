#include "Dragon.h"
#define ATTACK_POINTS 25
#define LOOT 1000
#define MAX_DAMAGE 100


Dragon::Dragon(const std::string& name) : BattleCard(name, ATTACK_POINTS, LOOT, MAX_DAMAGE){}
