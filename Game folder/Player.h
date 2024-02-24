#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Player {
    protected:
        Deck* mazzo;
    public:
        Player();
        ~Player();
        Deck* getMazzo();
        virtual Card pesca() = 0;
};

#endif