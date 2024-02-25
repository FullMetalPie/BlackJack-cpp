#include <iostream>
#include "Poker.h"
#include <ctime>
#include <random>

using namespace std;

/*COSTRUTTORE e DISTUTTORE*/
Poker::Poker() {
    dim = 0;
    cardsArray = nullptr;
    srand(time(nullptr));
}
Poker::~Poker() {
    delete[]cardsArray;
    dim = 0;
    cardsArray = nullptr;
}
/*GETTER*/
Card* Poker::getCardsArray() {
    return cardsArray;
}
/*PESCA*/
Card Poker::pesca() {
    int random = rand() % dim;
    Card cartaPescata = cardsArray[random];
    rimuovi(cardsArray[random], random);

    return cartaPescata;
}
/*INIZIALIZZA*/
void Poker::inizializza() {
    dim = 52;
    cardsArray = new Card[dim];
    int index = 0;
        
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
void Poker::stampa()  const {
    for (int i = 0; i < dim; i++) {
        cout << endl << "Carta " << (i+1)<< endl;
        cout << cardsArray[i];
    }
}
/*RIMOZIONE CARTA*/
Poker& Poker::rimuovi(Card c) {
    int pos = ricerca(c);
    
    if (pos == -1) {
        cout << "Carta non esistente.";
    } else {
        /* Shift a sinistra */
        for (int i = pos; i < dim - 1; i++) {
            cardsArray[i] = cardsArray[i + 1];
        }

        dim--;

        if (dim > 0) {
            Card* temp = new Card[dim];

            for (int i = 0; i < dim; i++) {
                temp[i] = cardsArray[i];
            }

            delete[] cardsArray;
            cardsArray = new Card[dim];

            for (int i = 0; i < dim; i++) {
                cardsArray[i] = temp[i];
            }

            delete[] temp;
        } else {
            delete[] cardsArray;
            cardsArray = nullptr;
        }
    }
}

Poker& Poker::rimuovi(Card c, int pos) {
    if (pos == -1) {
        cout << "Carta non esistente.";
    } else {
        /* Shift a sinistra */
        for (int i = pos; i < dim - 1; i++) {
            cardsArray[i] = cardsArray[i + 1];
        }

        dim--;

        if (dim > 0) {
            Card* temp = new Card[dim];

            for (int i = 0; i < dim; i++) {
                temp[i] = cardsArray[i];
            }

            delete[] cardsArray;
            cardsArray = new Card[dim];

            for (int i = 0; i < dim; i++) {
                cardsArray[i] = temp[i];
            }

            delete[] temp;
        } else {
            delete[] cardsArray;
            cardsArray = nullptr;
        }
    }

    return *this;
}
int Poker::ricerca(Card c) {
    int i = 0;
    while (i < dim && cardsArray[i] != c) {
        i++;
    }

    if (i < dim) {
        return i;
    } else {
        return -1;
    }
}
/*CALCOLA PUNTEGGIO*/
int Poker::calcPunti() const {
    int punti = 0;

    for (int i = 0; i < dim; i++) {
        punti += cardsArray[i].getValore();
    }

    return punti;
}
/*AGGIUNTA ELEMENTO*/
Poker& Poker::aggiungi(Card c) {
    if (dim != 0) {
        Card* temp = new Card[dim];

        for (int i = 0; i < dim; i++) {
            temp[i] = cardsArray[i];
        }

        delete[]cardsArray;

        dim++;
        cardsArray = new Card[dim];

        for (int i = 0; i < dim - 1; i++) {
            cardsArray[i] = temp[i];
        }

        delete[]temp;
    } else {
        dim = 1;
        cardsArray = new Card[dim];
    }

    cardsArray[dim - 1] = c;

    return *this;
}
/*RESET*/
Poker& Poker::reset() {
    delete[]cardsArray;
    dim = 0;

    return *this;
}
/*RICERCA ASSO*/
int Poker::trovaAsso() {
    int i = 0;

    while (i < dim && cardsArray[i].getNumero() != "Asso") {
        i++;
    }

    if (i < dim) {
        return i;
    } else {
        return -1;
    }
}