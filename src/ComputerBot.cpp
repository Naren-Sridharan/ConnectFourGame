/*<<<<<<< HEAD
#include "ComputerBot.h"
int CompBot::calculateNextMove(NuclearReactor nr){
    int x = rand()%Constants::COLUMNS;
    while(!nr.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
    return x;
};
=======*/

#include "ComputerBot.h"
//Bot designed to play against contestant
int CompBot::calculateNextMove(NuclearReactor cb){
        //BombCell *lastmove = cb.getLastMove();
        int x = rand()%Constants::COLUMNS;
        while(!cb.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
        return x;
}
//>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78
