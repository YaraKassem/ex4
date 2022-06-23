#include "Player.h"

Player::Player(const std::string &name, const std::string &job) : m_name(name),m_job(job),m_level(1),m_maxHP(100), m_force(5), m_healthPoints(100), m_coins(10)
{
    if( name.size() > 15)
    {
        throw InvalidPlayerName();
    }

    for(std::string::const_iterator it = name.begin(); it != name.end(); it++)
    {
         if (!(('a' <= *it  &&  *it <= 'z') || ('A' <= *it   &&  *it <= 'Z')))
        {
            throw InvalidPlayerName();
        }
    }
    
}

int Player::getHP() const
{
    return this->m_healthPoints;
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

int Player::getCoins() const
{
    return this->m_coins;
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

 const std::string Player::getName() const
 {
    return this->m_name;
 }

void Player::damageForce(int amount)
{
    this->m_force -= amount;
    if(this->m_force < 0)
    {
        this->m_force = 0;
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
    player.print(os);
    //printPlayerDetails(os, player.m_name, player.m_job, player.m_level, player.m_force, player.m_healthPoints, player.m_coins);
    return os;
}