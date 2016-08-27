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
