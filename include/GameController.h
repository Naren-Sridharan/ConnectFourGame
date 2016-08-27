#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
#include "NuclearReactor.h"
#include "Bot.h"
#include "Constants.h"

//Controller for the game
class GameController{

        //Bots that play against each other
        Bot *userbot,*compbot;

        //Boardused to play the game
        NuclearReactor *cb;

        //The player that has to make the next move
        Constants::PlayerType currentPlayer;

        //Gameplay between the bots

        //initial toss to decide which bot plays first
        bool toss();

        public:

        //constructor - creating game board and bots and then initialize the game
        GameController(Bot *userbot,Bot *compbot);

        void play();

};

#endif // GAMECONTROLLER_H_INCLUDED
