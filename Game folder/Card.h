#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
    private:
        string seed;
        string number;
        int value;
    public:
        /*COSTRUTTORI e DISTRUTTORE*/
        Card();
        Card(string seme, string num, int punteggio);
        ~Card();
        /*SETTER e GETTEr*/
        void setSeme(string seme);
        void setNumero(string num);
        void setValore(int punteggio);
        string getSeme();
        string getNumero();
        int getValore();
        /*OVERLOADING OPERATORE OUTPUT*/
        friend ostream& operator<<(ostream& out, const Card c);
        /*DISUGUAGLIANZA*/
        bool operator!=(Card c);
};

#endif