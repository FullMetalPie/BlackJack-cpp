#ifndef POKER_H
#define POKER_H

#include <iostream>
#include "Deck.h"

using namespace std;

class Poker : public Deck{
    public:
        /*COSTRUTTORE e DISTUTTORE*/
        Poker();
        ~Poker();
        /*GETTER*/
        Card* getCardsArray();
        /*PESCA*/
        Card pesca();
        /*INIZIALIZZA*/
        void inizializza();
        /*STAMPA*/
        void stampa() const ;
        /*RIMOZIONE CARTA*/
        Poker& rimuovi(Card c);
        Poker& rimuovi(Card c, int pos);
        int ricerca(Card c);
        /*CALCOLA PUNTEGGIO*/
        int calcPunti() const;
        /*AGGIUNTA ELEMENTO*/
        Poker& aggiungi(Card c);
        /*RESET*/
        Poker& reset();
        /*RICERCA ASSO*/
        int trovaAsso();
};

#endif