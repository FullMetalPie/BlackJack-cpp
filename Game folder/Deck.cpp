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
    int index;
        
    string semi[] = {"Cuori", "Quadri", "Fiori", "Picche"};
    string numeri[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Regina", "Re", "Asso"};


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            int valore = (j >= 10) ? 10 : j + 2;

            cardsArray[index] = Card(semi[i], numeri[j], valore);
            index++;
        }
    }
}
/*STAMPA*/
void Deck::stampa() {
    for (int i = 0; i < dim; i++) {
        cout << endl << "Carta " << (i+1)<< endl;
        cout << cardsArray[i];
    }
}
