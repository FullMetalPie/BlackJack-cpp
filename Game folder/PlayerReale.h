#include <iostream>
#include "Player.h"

using namespace std;

class PlayerReale : protected Player {
    protected: 
        Card* mano;
    public:
        PlayerReale();
        Card pesca();
        void stampaMano();
};