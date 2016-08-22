#ifndef CONTESTANTBOT_H_INCLUDED
#define CONTESTANTBOT_H_INCLUDED
#include "Bot.h"

//Bot to be designed bycontestant
class UserBot : public Bot{
    public:
    UserBot():Bot(Constants::RED){};
    int caculateNextMove(ConnectBombBoard cb);
};



#endif // CONTESTANTBOT_H_INCLUDED
