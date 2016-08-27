#ifndef CONTESTANTBOT_H
#define CONTESTANTBOT_H
#include "Constants.h"
#include "Bot.h"
//Bot to be designed bycontestant
class UserBot : public Bot{
    public:
    UserBot():Bot(Constants::USER){};
    int calculateNextMove(NuclearReactor );
};

#endif

