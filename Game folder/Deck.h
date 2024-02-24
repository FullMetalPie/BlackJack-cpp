#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
    private:
        Card* cardsArray;
        int dim;
    public:
        /*COSTRUTTORE e DISTRUTTORE*/
        Deck();
        ~Deck();
        /*SETTER e GETTER*/
        int getDim();

        void setDim(int dim);
        /*INIZIALIZZA*/
        void inizializza();
        /*STAMPA*/
        void stampa();
};

#endif