<<<<<<< HEAD:include/GameController.h
#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
#include "ContestantBot.h"
#include "NuclearReactor.h"
#include "ComputerBot.h"
//Controller for the game
class GameController{

        //Bots that play against each other
        Bot *userbot,*compbot;

        //Boardused to play the game
        NuclearReactor *cb;

        //The player that has to make the next move
        Constants::PlayerType currentPlayer;

        //Gameplay between the bots
        void play();

        //initial toss to decide which bot plays first
        bool toss();

        public:

        //constructor - creating game board and bots and then initialize the game
        GameController();
};

#endif // GAMECONTROLLER_H_INCLUDED
=======
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
>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78:include/GameController.h
