
#include "Bot.h"
//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot(Constants::PlayerType P):Bot(P){}
    int calculateNextMove(ConnectBombBoard *cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%COLUMNS;
        while(!cb->isBombPlaceable(x)) x = rand()%COLUMNS;
        return x;
    }
};
