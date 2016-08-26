#ifndef COMPUTERBOT_H
#define COMPUTERBOT_H
#include "Bot.h"
//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot(Constants::PlayerType P):Bot(P){};
    int calculateNextMove(NuclearReactor);
};

#endif