#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
    private:
        string seed;
        int number;
        int value;
    public:
        /*COSTRUTTORE e DISTRUTTORE*/
        Card();
        Card(string seed, int number, int value);
        ~Card();
        /*SETTER e GETTER*/
        string getSeed();
        int getNumber();
        int getValue();

        void setSeed(string seed);
        void setNumber(int number);
        void setValue(int value);
        void setAll(string seed, int number, int value);
        /*STAMPA*/
        friend ostream& operator<<(ostream& out, const Card c);
};

#endif