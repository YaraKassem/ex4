
#include "Merchant.h"
#define HEALAMOUNT 1
#define BUFFAMOUNT 1

Merchant::Merchant(const std::string &name) : Card(name){}

void Merchant::applyEncounter(Player &player) const 
{
    int choice;
    //what is the ostream?????
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    while(true)
    {
        scanf("%d",&choice);
        if(choice == 0 || choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            printInvalidInput();
        }
    }
    if((choice == 1 && player.getCoins() < 5)||(choice == 2 && player.getCoins() < 10))
    {
        //what is the ostream?????
        printMerchantInsufficientCoins(std::cout);
        return;
    }
    int cost = choice*5;
    if(choice == 1)
    {
        player.heal(HEALAMOUNT);
        //we can do assert that it is always true
        player.pay(cost);
    }
    else if( choice == 2)
    {
        player.buff(BUFFAMOUNT);
        //we can do assert that it is always true
        player.pay(cost);
    }
    //what is the ostream?????
    printMerchantSummary(std::cout, player.getName(), choice , cost);

}
