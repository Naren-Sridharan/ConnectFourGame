#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED
#include "BombBoard.h"

//Genral bot
class Bot{
    protected:
        char color;
    public:
        Bot(char);
        virtual int caculateNextMove(ConnectBombBoard)=0;

};

//Bot designed to play against contestant
class CompBot : public Bot{
    public:
    CompBot():Bot(Constants::BLUE){};
    int caculateNextMove(ConnectBombBoard);
};
#endif // BOT_H_INCLUDED
