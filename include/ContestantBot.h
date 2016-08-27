#ifndef CONTESTANTBOT_H_INCLUDED
#define CONTESTANTBOT_H_INCLUDED
#include "Bot.h"

//Bot to be designed bycontestant
class UserBot : public Bot{
    public:
    UserBot(Constants::PlayerType P):Bot(P){};
    int calculateNextMove(NuclearReactor);
};



#endif // CONTESTANTBOT_H_INCLUDED
