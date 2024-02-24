#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() {
    mazzo = new Deck;
    mazzo->inizializza();
}
Player::~Player() {
    delete mazzo;
}
Deck* Player::getMazzo() {
    return mazzo;
}