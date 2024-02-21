#include <iostream>
#include "Deck.h"

/*COSTRUTTORE e DISTRUTTORE*/
Deck::Deck() {
    dim = 0;
    cardsArray = nullptr;
}
Deck::~Deck() {
    delete[]cardsArray;
}
/*SETTER e GETTER*/
int Deck::getDim() {
    return dim;
}

void Deck::setDim(int dim) {
    this->dim = dim;
}
/*INIZIALIZZA*/
void Deck::inizializza() {
    dim = 52;
    cardsArray = new Card[dim];

    for (int i = 0; i < dim; i++) {
        if () {
            
        }
    }
}
/*STAMPA*/
void Deck::stampa() {
    for (int i = 0; i < dim; i++) {
        cout << cardsArray[i];
    }
}
/*OVERLOADING OPERATORE -*/
Deck* Deck::operator-(Card c) {

}