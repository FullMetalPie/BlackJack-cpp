#include <iostream>
#include "Deck.h"

/*COSTRUTTORE e DISTRUTTORE*/
Deck::Deck() {
    dim = 0;
    cardsArray = nullptr;
}
Deck::~Deck() {
}
/*SETTER e GETTER*/
int Deck::getDim() {
    return dim;
}

void Deck::setDim(int dim) {
    this->dim = dim;
}
