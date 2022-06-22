#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

class Card
{
    protected:

    std::string m_name;
    
    public:
    Card() = default;
    Card(const std::string& name);
    virtual ~Card() = default;
    //copy c'tor = and clone
    virtual void applyEncounter(Player &player) const =0;
    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

};

#endif

