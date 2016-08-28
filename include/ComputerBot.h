<<<<<<< HEAD
#ifndef COMPUTERBOT_H_INCLUDED
#define COMPUTERBOT_H_INCLUDED
#include "Bot.h"
//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot(Constants::PlayerType P):Bot(P){};
    int calculateNextMove(NuclearReactor);
};
#endif // COMPUTERBOT_H_INCLUDED
=======
#ifndef COMPUTERBOT_H
#define COMPUTERBOT_H
#include "Bot.h"
#include "Constants.h"

//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot():Bot(Constants::COMP){};
    int calculateNextMove(NuclearReactor);
};

#endif
>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78
