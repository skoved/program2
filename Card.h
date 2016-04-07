#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <string>
#include <map>

class Card{//Represents a card
    int value;
    int suit;
public:
    static std::map<int, std::string> suits;
    Card(int value, int suit){//creates a card
        this->value = value; this->suit = suit;
    };

    Card(const Card &card){//copy constructor
        this->value = card.value;
        this->suit = card.suit;
    };

    int getVal(){//returns value
        return value;
    };
    int getSuit(){//returns suit
        return suit;
    };

    void print(){//formats and prints the data for a card
        std::cout<<suits.at(suit)<< " "<<value<<std::endl;
    };
};
std::map<int, std::string> Card::suits = {{0, "Heart"}, {1, "Diamonds"}, {2, "Clubs"}, {3, "Spade"}};//initializes the map for suits
#endif
