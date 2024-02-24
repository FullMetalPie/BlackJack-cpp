#include <iostream>
#include "Card.h"

/*COSTRUTTORI e DISTRUTTORE*/
Card::Card() {
    seed = "undefined";
    number = "0";
    value = 0;
}
Card::Card(string seme, string num, int punteggio) {
    seed = seme;
    number = num;
    value = punteggio;
}
Card::~Card() {

}
/*SETTER e GETTEr*/
void Card::setSeme(string seme) {
    seed = seme;
}
void Card::setNumero(string num) {
    number = num;
}
void Card::setValore(int punteggio) {
    value = punteggio;
}
string Card::getSeme() {
    return seed;
}
string Card::getNumero() {
    return number;
}
int Card::getValore() {
    return value;
}
/*OVERLOADING OPERATORE OUTPUT*/
ostream& operator<<(ostream& out, const Card c) {
    out << "Seme: " << c.seed << endl;
    out << "Numero: " << c.number << endl;
    out << "Valore: " << c.value << endl;

    return out;
}
/*DISUGUAGLIANZA*/
bool Card::operator!=(Card c) {
    if (seed != c.seed && number != c.number && value != c.value) {
        return true;
    } else {
        return false;
    }
}