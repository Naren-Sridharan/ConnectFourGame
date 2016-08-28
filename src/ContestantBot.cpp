<<<<<<< HEAD
#include "ContestantBot.h"
int UserBot::calculateNextMove(NuclearReactor nr){
    int x = rand()%Constants::COLUMNS;
    while(!nr.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
    return x;
};
=======

#include "ContestantBot.h"

//Bot to be designed bycontestant

int UserBot::calculateNextMove(NuclearReactor cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%Constants::COLUMNS;
        while(!cb.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
        return x;
}



>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78
