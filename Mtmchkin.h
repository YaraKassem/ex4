#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Headers.h"


class Mtmchkin
{

    std::list<Player *> m_players;
    std::queue<Card *> m_cards;
    std::vector<Player *> m_winners;
    std::vector<Player *> m_losers;
    int m_numOfActivePlayers;
    int m_numOfRoundsPlayed;

    static void checkTeamSize(double &teamSize);
    static bool gangAddCard(Gang *currentGangCard, std::string& card);
    static bool checkPlayer(std::string &name, std::string &type);
    static bool getNameAndType(std::string &name, std::string &type);
    bool addCard(std::string &card, Gang **currentGangCard, bool* inGang);
    void startGame();
    void clearCards();

public:
    /*
     * C'tor of Mtmchkin class
     *
     * @param filename - a file which contains the cards of the deck.
     * @return
     *      A new instance of Mtmchkin.
     */
    Mtmchkin(const std::string fileName);

    Mtmchkin(const Mtmchkin&) = delete;

    Mtmchkin& operator=(const Mtmchkin&) = delete;
    
    ~Mtmchkin();


    /*
     * Play the next Round of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void playRound();

    /*
     * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void printLeaderBoard() const;

    /*
     *  Checks if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isGameOver() const;

    /*
     *  Returns the number of rounds played.
     *
     *  @return
     *          int - number of rounds played
     */
    int getNumberOfRounds() const;



};



#endif /* MTMCHKIN_H_ */
