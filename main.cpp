#include "Mtmchkin.h"

int main()
{
    try
    {
        const int MAX_NUMBER_OF_ROUNDS = 100;
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const DeckFileNotFound &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const DeckFileInvalidSize &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const DeckFileFormatError &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const InvalidCardName &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const InvalidPlayerName &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
