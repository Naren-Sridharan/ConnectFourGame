
#include "ComputerBot.h"
//Bot designed to play against contestant

int CompBot::calculateNextMove(NuclearReactor cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%Constants::COLUMNS;
        while(!cb.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
        return x;
}