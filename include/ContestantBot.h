#ifndef CONTESTANTBOT_H
#define CONTESTANTBOT_H
#include "Bot.h"

//Bot to be designed bycontestant
class UserBot : public Bot{
    public:
    UserBot(Constants::PlayerType P):Bot(P){};
    int calculateNextMove(ConnectBombBoard *cb);
};

#endif

