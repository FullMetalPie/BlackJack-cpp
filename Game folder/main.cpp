#include <iostream>
#include "Poker.h"
#include <stdlib.h>

using namespace std;

void stampaRegole();
void situazione(const Poker& p1, const Poker& p2);
int checkWin(const Poker& p1, const Poker& p2, bool finished);

int main() {
    Poker mazzo;
    Poker manoPlayer, manoBanco;
    Card cardTemp;
    
    mazzo.inizializza();

    int scelta = 0;
    int scelta2 = 0;
    bool finished;
    
    do {
        do {
            system("CLS");
            cout << "BLACK JACK - Creato da Pietri Andrea" << endl;
            cout << "1. Gioca;" << endl;
            cout << "2. Regole;" << endl;
            cout << "3. Esci." << endl;
            cout << "Operazione: ";
            cin >> scelta;
        } while (scelta < 1 || scelta > 3);

        switch (scelta) {
            case 1:
                manoPlayer.reset();
                manoBanco.reset();
                finished = false;
                system("CLS");
                /*primo turno*/
                manoPlayer.aggiungi(mazzo.pesca());
                manoPlayer.aggiungi(mazzo.pesca());

                manoBanco.aggiungi(mazzo.pesca());
                situazione(manoPlayer, manoBanco);
                /*loop di gioco*/
                while (checkWin(manoPlayer, manoBanco, finished) == 0) {
                    do {
                        cout << endl << "1. Chiedi;" << endl;
                        cout << "2. Stai;" << endl;
                        cout << "3. Usa un asso con valore 1." << endl;
                        cout << "Operazione: ";
                        cin >> scelta2;
                    } while (scelta2 < 1 || scelta2 > 3);

                    switch (scelta2) {
                        case 1:
                            system("CLS");
                            manoPlayer.aggiungi(mazzo.pesca());
                            while (manoBanco.calcPunti() < 17) {
                                manoBanco.aggiungi(mazzo.pesca());
                            }
                            situazione(manoPlayer, manoBanco);
                            getchar();
                            getchar();
                            if (manoPlayer.calcPunti() > 21) {
                                finished = true;
                            } else {
                                if (manoPlayer.calcPunti() < manoBanco.calcPunti() && manoBanco.calcPunti() <=21) {
                                    finished = false;
                                }
                            }
                            break;
                        case 2:
                            system("CLS");
                            while (manoBanco.calcPunti() < 17) {
                                manoBanco.aggiungi(mazzo.pesca());
                            }
                            situazione(manoPlayer, manoBanco);
                            getchar();
                            getchar();
                            finished = true;
                            break;
                        case 3:
                            system("CLS");
                            if (manoPlayer.trovaAsso() != -1) {
                                if (manoPlayer.getCardsArray()[manoPlayer.trovaAsso() != -1].getValore() == 1) {
                                    manoPlayer.getCardsArray()[manoPlayer.trovaAsso() != -1].setValore(10);
                                } else {
                                    manoPlayer.getCardsArray()[manoPlayer.trovaAsso() != -1].setValore(1);
                                }
                            } else {
                                situazione(manoPlayer, manoBanco);
                                cout << "Non hai assi in mano."<< endl;
                            }
                            getchar();
                            getchar();
                            break;
                    }
                }

                if (checkWin(manoPlayer, manoBanco, finished) == 2) {
                    cout << "Hai perso.";
                } else if (checkWin(manoPlayer, manoBanco, finished) == 1) {
                    cout << "Hai vinto.";
                }
                getchar();
                getchar();
                break;
            case 2:
                system("CLS");
                stampaRegole();
                getchar();
                getchar();
                break;
        }

    } while (scelta != 3);

    system("CLS");
    cout << "Grazie per aver giocato.";
    return 0;
}

void stampaRegole() {
    cout << "Regole del Blackjack:\n\n";
    cout << "1. Obiettivo: Ottenere una mano di carte il piu' vicino possibile a 21 senza superarlo.\n";
    cout << "2. Valore delle carte:\n";
    cout << "   - Le carte numeriche valgono il loro valore nominale.\n";
    cout << "   - Le figure (Jack, Regina, Re) valgono 10 punti ciascuna.\n";
    cout << "   - L'Asso puo' valere 1 o 11 punti, a seconda di cosa e' piu' vantaggioso per la mano.\n";
    cout << "3. Gioco:\n";
    cout << "   - Il giocatore riceve due carte coperte.\n";
    cout << "   - Il banco riceve una carta coperta e una scoperta.\n";
    cout << "   - Il giocatore puo' 'chiedere' (ricevere una carta aggiuntiva) o 'stare' (rimanere con le carte attuali).\n";
    cout << "   - Il banco segue regole specifiche per chiedere o stare.\n";
    cout << "4. Vincita e Perdita:\n";
    cout << "   - Il giocatore vince se ha una mano con un valore totale piu' vicino a 21 rispetto al banco senza superarlo.\n";
    cout << "   - Il giocatore perde se supera 21 punti.\n";
    cout << "   - Se il banco supera 21 punti, il giocatore vince.\n";
    cout << "   - In caso di parita', si verifica un 'push' e il giocatore recupera la scommessa.\n";
    cout << "5. Blackjack:\n";
    cout << "   - Un 'Blackjack' e' ottenuto con un Asso e una carta da 10 punti iniziali (10, Jack, Regina, Re) nelle prime due carte.\n";
    cout << "     Il Blackjack paga generalmente 3:2.\n";
}

void situazione(const Poker& p1, const Poker& p2) {
    system("CLS");
    cout << endl << "LA TUA MANO: ";
    p1.stampa();
    cout << endl << "Punti: " << p1.calcPunti() << endl;

    cout << endl << "MANO DEL BANCO: ";
    p2.stampa();
    cout << endl << "Punti: " << p2.calcPunti() << endl;
}

int checkWin(const Poker& p1, const Poker& p2, bool finished) {
    int flag = 0; //0 = nessuno vince | 1 = vince il player | 2 = vince il banco 
    
    if (!finished) {
        return flag;
    } else {
        int puntiGiocatore = p1.calcPunti();
        int puntiBanco = p2.calcPunti();

        if (puntiGiocatore > 21 && puntiBanco <= 21) {
            // Il giocatore ha sballato, il banco vince
            flag = 2;
        } else {
            if (puntiBanco > 21 && puntiGiocatore <= 21) {
                // Il banco ha sballato, il giocatore vince
                flag = 1;
            } else { 
                if (puntiGiocatore == puntiBanco) {
                    // Punteggi uguali, nessuno vince
                    flag = 0;
                } else {
                    if (puntiGiocatore == 21 && puntiBanco != 21) {
                        // Il giocatore ha fatto Blackjack, vince il giocatore
                        flag = 1;
                    } else { 
                        if (puntiBanco == 21 && puntiGiocatore != 21) {
                            // Il banco ha fatto Blackjack, vince il banco
                            flag = 2;
                        }
                    }
                }
            }
        }
        if (puntiGiocatore < 21 && puntiBanco < 21) {
            // Nessun sballamento, confronto i punteggi
            if (puntiGiocatore > puntiBanco) {
                flag = 1; // Il giocatore ha più punti, vince il giocatore
            } else {
                flag = 2; // Il banco ha più punti, vince il banco
            }
        }
    }
    return flag;
}