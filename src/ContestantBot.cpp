#include "ContestantBot.h"
int UserBot::calculateNextMove(NuclearReactor nr){
    int x = rand()%Constants::COLUMNS;
    while(!nr.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
    return x;
};
