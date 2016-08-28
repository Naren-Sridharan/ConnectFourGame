#ifndef COMPUTERBOT_H
#define COMPUTERBOT_H
#include "Bot.h"
#include "Constants.h"

//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot():Bot(Constants::COMP){};
    CompBot(CompBot const &U):Bot(Constants::COMP){};
    int calculateNextMove(NuclearReactor);
};

#endif //COMPUTERBOT_H
