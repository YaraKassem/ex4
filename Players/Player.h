#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string.h>

#include "../Exception.h"


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
    Player(const std::string& m_name, const std::string& m_job);

    //copy c'tor
    Player(const Player& player) = default;

    //assignment operator
    Player& operator=(const Player& other) = default;

    //d'tor
    virtual ~Player() = default;
    
    //bumps the player's level by 1
    void levelUp();

    //level getter
    int getLevel() const;
    
    //increases player's force by buffAmount
    void buff(int buffAmount);
    
    //heals player's HP by healAmount
    virtual void heal(int healAmount);

    //damages players by damageAmount
    void damage(int damageAmount);

    //lowers force by amount
    void damageForce(int amount);

    //returns HP
    int getHP() const;
    //returns the name
    const std::string getName() const;

    //returns the coins amount
    int getCoins() const;

    //lowers 10 from HP unless it's rogue
    virtual void pitfall() = 0;

    //lowers 10 from HP unless it's fighter
    virtual void barFight() = 0;

    //adds 10 only to wizard
    virtual void fairyEncounter() = 0;

    //if healthPoints is 0 returns true - is knocked out
    bool isKnockedOut() const;

    //adds coins
    virtual void addCoins(int addition);

    //performs payment and returns true if it succeeds or false if it fails
    bool pay(int coinsAmount);

    // returns attack strength which is level + force
    virtual int getAttackStrength() const;
    
    //pure virtual , print according to type
    virtual void print(std::ostream& os) const = 0;

    //printing operator
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //EX2_Player_H