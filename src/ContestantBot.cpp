
#include "Bot.h"

//Bot to be designed bycontestant
class UserBot : public Bot{
    public:
    UserBot(Constants::PlayerType P):Bot(P){}
    int calculateNextMove(ConnectBombBoard *cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%COLUMNS;
        while(!cb->isBombPlaceable(x)) x = rand()%COLUMNS;
        return x;
    }
};




