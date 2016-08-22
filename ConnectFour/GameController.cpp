#include "GameController.h"


void GameController::play(){
    //cout << "Start Play" << endl;
    while(cb->getLastMove().color == Constants::EMPTY || !isGameOver()){
        //cout << "turn " << endl;
        if(currentPlayer == Constants::userbotname){
            cb->dropBomb(userbot->caculateNextMove(*cb),Constants::RED,currentPlayer);
            currentPlayer = Constants::Constants::compbotname;
        }
        else{
            cb->dropBomb(compbot->caculateNextMove(*cb),Constants::BLUE,currentPlayer);
            currentPlayer = Constants::userbotname;
        }
    }
    fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
    f << "\n\t\"winner\" : \"" << ((cb->getLastMove().getColor() == Constants::RED) ? Constants::userbotname : Constants::Constants::compbotname) << "\"\n}";
    //cout << "End Play" << endl;
}

//initial toss to decide which bot plays first
bool GameController::toss(){
    srand(time(NULL));
    return rand()%2;
}

//check whether the game is over
bool GameController::isGameOver(){
    //cout << "Checking if game is over" << endl;
    int k,directions[8] = {0};
    bool flags[8] = {false};
    BombCell bc = cb->lastmove;
    int row = bc.row;
    int column = bc.column;
    char color = bc.color;
    for(k = 0; k < Constants::COLUMNS; k++)
        if(cb->isBombPlaceable(k))
            break;
    if(k == Constants::COLUMNS){
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"winner\" : \"Draw\"\n}";
        f.close();
        //cout << "End Play" << endl;
        exit(0);
    }
    if(row == -1 && column == -1)
        return false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            if(directions[j] == i && !flags[j]){
                switch(j){
                    case 0:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS  && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(cb->getCellColor(row-i-1,column-i-1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 1:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS){
                            if(cb->getCellColor(row-i-1,column) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 2:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(cb->getCellColor(row-i-1,column+i+1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 3:
                        if(column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(cb->getCellColor(row,column+i+1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 4:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(cb->getCellColor(row+i+1,column+i+1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 5:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS){
                            if(cb->getCellColor(row+i+1,column) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 6:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(cb->getCellColor(row+i+1,column-i-1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 7:
                        if(column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(cb->getCellColor(row,column-i-1) == color){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                }
            }
        }
    }
    int points[3][2];
    if((directions[0]+directions[4]) >= 3){
        int i = 0;
        for(int j = 0; i<4 && j < directions[0]; j++){
            points[i][0] = row - 1 - i;
            points[i++][1] = column - 1 - i;
        }
        for(int j = 0; i<4 && j < directions[4]; j++){
            points[i][0] = row + 1 + i;
            points[i++][1] = column + 1 + i;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return true;
    }
    else if((directions[1]+directions[5]) >= 3){
        int i = 0;
        for(int j = 0; i<4 && j < directions[1]; j++){
            points[i][0] = row - 1 - i;
            points[i++][1] = column;
        }
        for(int j = 0; i<4 && j < directions[3]; j++){
            points[i][0] = row + 1 + i;
            points[i++][1] = column;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return true;
    }
    else if((directions[2]+directions[6]) >= 3){
        int i = 0;
        for(int j = 0; i<4 && j < directions[2]; j++){
            points[i][0] = row - 1 - i;
            points[i++][1] = column + 1 + i;
        }
        for(int j = 0; i<4 && j < directions[6]; j++){
            points[i][0] = row + 1 + i;
            points[i++][1] = column - 1 - i;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return true;
    }
    else if((directions[3]+directions[7]) >= 3){
        int i = 0;
        for(int j = 0; i<4 && j < directions[3]; j++){
            points[i][0] = row;
            points[i++][1] = column + 1 + i;
        }
        for(int j = 0; i<4 && j < directions[7]; j++){
            points[i][0] = row;
            points[i++][1] = column - 1 - i;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return true;
    }
    return false;
}

GameController::GameController(){
    //cout << "Game Controller Created" << endl;
    if(toss()){
        currentPlayer = Constants::userbotname;
    }
    else{
        currentPlayer = Constants::compbotname;
    }
    cb = new ConnectBombBoard(currentPlayer);
    play();
}
