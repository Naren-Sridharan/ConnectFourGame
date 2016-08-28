#include "ContestantBot.h"

//Bot to be designed bycontestant

int UserBot::calculateNextMove(NuclearReactor cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%Constants::COLUMNS;
        while(!cb.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
        return x;
}
