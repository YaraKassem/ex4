
#include "Merchant.h"
#define HEALAMOUNT 1
#define BUFFAMOUNT 1

Merchant::Merchant(const std::string &name) : Card(name) {}

bool checkIfLineIsANumber(std::string line)
{
    int size = line.length();
    for (int i = 0; i < size; i++)
    {
        if (isdigit(line[i]))
        {
            return true;
        }
    }

    return false;
}

void Merchant::applyEncounter(Player &player) const
{
    double choice;
    std::string line;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    while (true)
    {
        std::getline(std::cin, line);
        if (line.empty())
        {
            printInvalidInput();
            continue;
        }
        if(!checkIfLineIsANumber(line))
        {
            printInvalidInput();
            continue;
        }
        try
        {
            choice = std::stod(line);
        }
        catch (const std::out_of_range &e)
        {
            printInvalidInput();
            continue;
        }
        if (choice == 0 || choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            printInvalidInput();
        }
    }

    // while (true)
    // {
    //     std::cin >> choice;

    //     if (std::cin.fail())
    //     {
    //         std::cin.clear();
    //         std::cin.ignore('\n');
    //         printInvalidInput();
    //         continue;
    //     }
    //}
    if ((choice == 1 && player.getCoins() < 5) || (choice == 2 && player.getCoins() < 10))
    {
        printMerchantInsufficientCoins(std::cout);
        return;
    }
    int cost = choice * 5;
    if (choice == 1)
    {
        player.heal(HEALAMOUNT);
        // we can do assert that it is always true
        player.pay(cost);
        printMerchantSummary(std::cout, player.getName(), choice, cost);
    }
    else if (choice == 2)
    {
        player.buff(BUFFAMOUNT);
        // we can do assert that it is always true
        player.pay(cost);
        printMerchantSummary(std::cout, player.getName(), choice, cost);
    }
}
