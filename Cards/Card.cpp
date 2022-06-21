#include "Card.h"

Card::Card(const std::string &name) : m_name(name)
{
    if (name.size() > 15)
    {
        throw InvalidCardName();
    }

    for (std::string::const_iterator it = name.begin(); it != name.end(); it++)
    {
        if (!(('a' < *it < 'z') || ('A' < *it < 'Z')))
        {
            throw InvalidCardName();
        }
    }

    // if (name != "Barfight" || name != "Dragon" || name != "Fairy" ||
    //     name != "Goblin" || name != "Merchant" || name != "Pitfall" || name != "Treasure")
    // {
    //     // throw invalid format
    //     throw InvalidCardName();//may be wrong
    // }

}

void Card::print(std::ostream& os) const
{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
}


std::ostream &operator<<(std::ostream &os, const Card &card)
{
    card.print(os);
    return os;
}