#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName) : m_numOfRoundsPlayed(0)
{
    // if there is a problem with the cards , do we print anything else?
    std::ifstream file(fileName);
    if (file.fail())
    {
        throw DeckFileNotFound();
    }
    std::string card;
    bool inGang = false;
    Gang *currentGangCard = nullptr;
    int numOfCards = 0;
    int lineCounter = 0;

    while (std::getline(file, card))
    {
        lineCounter++;
        if (inGang == false)
        {
            if (addCard(card, &currentGangCard, &inGang) == false)
            {
                std::string lineCounterStr = std::to_string(lineCounter);
                clearCards();
                throw DeckFileFormatError(lineCounterStr);
            }
            else
            {
                numOfCards++;
            }
        }
        else if (inGang)
        {
            if (card == "EndGang")
            {
                inGang = false;
            }
            else
            {
                if (gangAddCard(currentGangCard, card) == false)
                {
                    std::string lineCounterStr = std::to_string(lineCounter);
                    clearCards();
                    throw DeckFileFormatError(lineCounterStr);
                }
            }
        }
    }
    if (numOfCards < 5)
    {
        clearCards();
        throw DeckFileInvalidSize();
    }

    this->startGame();
}

void Mtmchkin::clearCards()
{
    while (this->m_cards.size() != 0)
    {
        Card *currCard = this->m_cards.front();
        delete currCard;
        this->m_cards.pop();
    }
}

void Mtmchkin::startGame()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    double teamSize;

    checkTeamSize(teamSize);
    this->m_numOfActivePlayers = teamSize;

    while (teamSize > 0) // players scan
    {
        std::string name;
        std::string type;
        printInsertPlayerMessage();

        while (true)
        {
            if (!checkPlayer(name, type))
            {
                continue;
            }

            if (type == "Wizard")
            {
                this->m_players.push_back(new Wizard(name));
                break;
            }
            else if (type == "Rogue")
            {
                this->m_players.push_back(new Rogue(name));
                break;
            }
            else if (type == "Fighter")
            {
                this->m_players.push_back(new Fighter(name));
                break;
            }
            else
            {
                printInvalidClass();
                continue;
            }
        }
        teamSize--;
    }
}

void Mtmchkin::checkTeamSize(double &teamSize)
{
    while (true)
    {
        std::cin >> teamSize;
        if (!std::cin)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        else if (teamSize == 2 || teamSize == 3 || teamSize == 4 || teamSize == 5 || teamSize == 6)
        {
            return;
        }
        else
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
            ;
        }
    }
}

// does not check if the type is one of the 3 types
bool Mtmchkin::checkPlayer(std::string &name, std::string &type)
{
    std::cin >> name;
    if (!std::cin)
    {
        printInvalidName();
        std::cin >> type;
        return false;
    }

    else if (name.size() > 15)
    {
        printInvalidName();
        std::cin >> type;
        return false;
    }

    for (std::string::const_iterator it = name.begin(); it != name.end(); it++)
    {
        if (!(('a' <= *it && *it <= 'z') || ('A' <= *it && *it <= 'Z')))
        {
            printInvalidName();
            std::cin >> type;
            return false;
        }
    }
    std::cin >> type;
    if (!std::cin)
    {
        printInvalidClass();
        return false;
    }

    return true;
}

bool Mtmchkin::gangAddCard(Gang *currentGangCard, std::string &card)
{

    if (card == "Dragon")
    {
        currentGangCard->addCard(new Dragon(card));
    }

    else if (card == "Goblin")
    {
        currentGangCard->addCard(new Goblin(card));
    }

    else if (card == "Vampire")
    {
        currentGangCard->addCard(new Vampire(card));
    }

    else
    {
        return false;
    }
    return true;
}

bool Mtmchkin::addCard(std::string &card, Gang **currentGangCard, bool *inGang)
{
    if (card == "Barfight")
    {
        this->m_cards.push(new Barfight(card));
    }

    else if (card == "Dragon")
    {
        this->m_cards.push(new Dragon(card));
    }

    else if (card == "Fairy")
    {
        this->m_cards.push(new Fairy(card));
    }

    else if (card == "Gang")
    {
        *currentGangCard = new Gang(card);
        this->m_cards.push(*currentGangCard);
        *inGang = true;
    }

    else if (card == "Goblin")
    {
        this->m_cards.push(new Goblin(card));
    }

    else if (card == "Merchant")
    {
        this->m_cards.push(new Merchant(card));
    }

    else if (card == "Treasure")
    {
        this->m_cards.push(new Treasure(card));
    }

    else if (card == "Vampire")
    {
        this->m_cards.push(new Vampire(card));
    }

    else if (card == "Pitfall")
    {
        this->m_cards.push(new Pitfall(card));
    }

    else
    {
        return false;
    }

    return true;
}

Mtmchkin::~Mtmchkin()
{
    for (std::list<Player *>::iterator it = this->m_players.begin(); it != this->m_players.end(); it++)
    {
        delete *it;
    }

    while (this->m_cards.size() != 0)
    {
        Card *currCard = this->m_cards.front();
        delete currCard;
        this->m_cards.pop();
    }
}

bool Mtmchkin::isGameOver() const
{
    if (this->m_numOfActivePlayers == 0)
    {
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const
{
    return this->m_numOfRoundsPlayed;
}

void Mtmchkin::playRound()
{
    this->m_numOfRoundsPlayed++;
    printRoundStartMessage(this->m_numOfRoundsPlayed);
    for (std::list<Player *>::iterator it = this->m_players.begin(); it != this->m_players.end(); it++)
    {
        if ((*it)->getLevel() != 10 && (*it)->getHP() != 0)
        {
            printTurnStartMessage((*it)->getName());
            Card *currCard = this->m_cards.front();
            currCard->applyEncounter(*(*it));
            if ((*it)->getLevel() == 10)
            {
                this->m_numOfActivePlayers--;
                this->m_winners.push_back(*it);
            }
            if ((*it)->getHP() == 0)
            {
                this->m_numOfActivePlayers--;
                this->m_losers.push_back(*it);
            }
            this->m_cards.pop();
            this->m_cards.push(currCard);
        }

        if (this->m_numOfActivePlayers == 0)
        {
            this->m_numOfRoundsPlayed++;
            printGameEndMessage();
            return;
        }
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int i = 0;
    int size = this->m_winners.size();
    for (; i < size; i++)
    {
        printPlayerLeaderBoard(i + 1, *(this->m_winners[i]));
    }

    for (std::list<Player *>::const_iterator it = this->m_players.begin(); it != this->m_players.end(); it++)
    {
        if ((*it)->getLevel() != 10 && (*it)->getHP() != 0)
        {
            printPlayerLeaderBoard(i + 1, *(*it));
            i++;
        }
    }
    size = this->m_losers.size();
    for (int j = size - 1; j >= 0; j--)
    {
        printPlayerLeaderBoard(i + 1, *(this->m_losers[j]));
        i++;
    }
}