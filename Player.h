#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>

class Player{
    private:
        int budget;
        std::string name;
    public:
        Card hand;
        Player(std::string name, int budget);//creates a player with a name and budget
        std::string getName();//returns the name of the player
        int getBudget();//returns the budget of the player
        bool bet(int amount);//the player bets the amount passed, returns false if the player cannot bet the amount
        void collectWinnings(int amount);//adds winnings to the players budget
};
#endif
