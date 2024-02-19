#include <iostream>
#include "Card.h"

/*COSTRUTTORE e DISTRUTTORE*/
Card::Card() {
    seed = "";
    number = 0;
    value = 0;
}
Card::Card(string seed, int number, int value) {
    this->seed = seed; 
    this->number = number;
    this->value = value;
}
Card::~Card() {

}
/*SETTER e GETTER*/
string Card::getSeed() {
    return seed;
}
int Card::getNumber() {
    return number;
}
int Card::getValue() {
    return value;
}

void Card::setSeed(string seed) {
    this->seed = seed;
}
void Card::setNumber(int number) {
    this->number = number;
}
void Card::setValue(int value) {
    this->value = value;
}
void Card::setAll(string seed, int number, int value) {
    this->seed = seed; 
    this->number = number;
    this->value = value;
}
/*STAMPA*/
ostream& operator<<(ostream& out, const Card c) {
    out << "Seed: " << c.seed << endl;
    out << "Number: " << c.number << endl;
    out << "Value: " << c.value << endl;

    return out;
}