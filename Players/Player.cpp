#include "Player.h"

Player::Player(const std::string &name, const std::string &job, int maxHP, int force) : m_name(name),m_job(job),m_level(1), m_maxHP(maxHP), m_force(force), m_healthPoints(maxHP), m_coins(10)
{
    if (maxHP <= 0)
    {
        this->m_maxHP = 100;
    }

    if (force <= 0)
    {
        this->m_force = 5;
    }

    if( name.size() > 15)
    {
        throw InvalidPlayerName();
    }

    for(std::string::const_iterator it = name.begin(); it != name.end(); it++)
    {
         if (!(('a' < *it < 'z') || ('A' < *it < 'Z')))
        {
            throw InvalidPlayerName();
        }
    }
    
}


void Player::levelUp()
{
    if (this->m_level < 10)
    {
        this->m_level++;
    }
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int buffAmount)
{
    if (buffAmount > 0)
    {
        this->m_force += buffAmount;
    }
}

void Player::heal(int healAmount)
{
    if (healAmount > 0)
    {
        this->m_healthPoints += healAmount;
        if (this->m_healthPoints > this->m_maxHP)
        {
            this->m_healthPoints = this->m_maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if (damageAmount > 0)
    {
        this->m_healthPoints -= damageAmount;
        if (this->m_healthPoints < 0)
        {
            this->m_healthPoints = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return this->m_healthPoints == 0 ? true : false;
}

void Player::addCoins(int addition)
{
    if (addition > 0)
    {
        this->m_coins += addition;
    }
}

bool Player::pay(int coinsAmount)
{
    if (this->m_coins < coinsAmount)
    {
        return false;
    }
    if (coinsAmount <= 0)
    {
        return true;
    }
    this->m_coins -= coinsAmount;
    return true;
}

int Player::getAttackStrength() const
{
    return (this->m_force + this->m_level);
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os, player.m_name, player.m_job, player.m_level, player.m_force, player.m_healthPoints, player.m_coins);
}