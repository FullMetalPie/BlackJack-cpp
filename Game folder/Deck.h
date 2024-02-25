#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
    protected:
        Card* cardsArray;
        int dim;
    public:
        /*COSTRUTTORE e DISTRUTTORE*/
        Deck();
        virtual ~Deck();
        /*SETTER e GETTER*/
        int getDim();

        void setDim(int dim);
        /*INIZIALIZZA*/
        virtual void inizializza() = 0;
};

#endif