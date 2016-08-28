<<<<<<< HEAD
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
#endif
=======
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
#endif 
>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78
