#include "GameController.h"


void GameController::play(){
    //cout << "Start Play" << endl;
    while(cb->getRecentOpponentMove().getStatus() == Constants::EMPTY || cb->isGameOver() == Constants::NOPLAYER){
        //cout << "turn " << endl;
        if(currentPlayer == Constants::USER){
            cb->dropBomb(userbot->calculateNextMove(*cb),Constants::USER);
            currentPlayer = Constants::COMP;
        }
        else{
            cb->dropBomb(compbot->calculateNextMove(*cb),Constants::COMP);
            currentPlayer = Constants::USER;
        }
    }
    writeToJson(((currentPlayer)?Constants::userbotname:Constants::compbotname));
}

//initial toss to decide which bot plays first
bool GameController::toss(){
    srand(time(NULL));
    return rand()%2;
}


GameController::GameController(Bot * userbot,Bot * compbot){
    //cout << "Game Controller Created" << endl;
    this->userbot = userbot;
    this->compbot = compbot;
    if(toss()){
        currentPlayer = Constants::USER;
    }
    else{
        currentPlayer = Constants::COMP;
    }
    cb = new NuclearReactor(currentPlayer);
}
