#include "ComputerBot.h"
int CompBot::calculateNextMove(NuclearReactor nr){
    int x = rand()%Constants::COLUMNS;
    while(!nr.isBombPlaceable(x)) x = rand()%Constants::COLUMNS;
    return x;
};
