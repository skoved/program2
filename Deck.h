#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Deck{//represents a deck of cards using a deque
    std::deque<Card> deck;//holds the deck
public:
    Deck(){//creates an unshuffled deck of cards
        for(int i=1; i<14; i++){
            for(int j=0; j<4; j++)
                deck.push_back(Card(i, j));
        }
    };

    void shuffle(){//shuffles the deck using stl random_shuffle
        if(!(deck.empty())){
            srand(time(NULL));
            std::random_shuffle(deck.begin(), deck.end());
        }
    };

    Card draw(){//returns and deletes the last value in the deque
        Card card = Card((deck.front()));
        deck.pop_front();
        return card;
    };

    bool empty(){//returns true if there are no cards in the deck
        return deck.empty();
    };
};
#endif
