#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string.h>
#include "utilities.h"


class Player
{
    protected:

    std::string m_name;
    std::string m_job;
    int m_level;
    int m_maxHP;
    int m_force;
    int m_healthPoints;
    int m_coins;

    public:
    // c'tor
    Player(const std::string& m_name, const std::string& m_job, int m_maxHP = 100, int m_force = 5);
    //copy c'tor
    Player(const Player& player) = default;
    //assignment operator
    Player& operator=(const Player& other) = default;
    //d'tor
    ~Player() = default;
    
    //bumps the player's level by 1
    void levelUp();

    //level getter
    int getLevel() const;
    
    //increases player's force by buffAmount
    void buff(int buffAmount);
    
    //heals player's HP by healAmount
    void heal(int healAmount);

    //damages players by damageAmount
    void damage(int damageAmount);

    //if healthPoints is 0 returns true - is knocked out
    bool isKnockedOut() const;

    //adds coins
    void addCoins(int addition);

    //performs payment and returns true if it succeeds or false if it fails
    bool pay(int coinsAmount);

    // returns attack strength which is level + force
    int getAttackStrength() const;
    
    //printing operator
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //EX2_Player_H