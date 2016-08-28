#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED
#include "NuclearReactor.h"

//Genral bot
class Bot{
    protected:
        Constants::PlayerType ptype;
    public:
        Bot(Constants::PlayerType);
        virtual int calculateNextMove(NuclearReactor)=0;

};
#endif //BOT_H
