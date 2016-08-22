#include "BombBoard.h"

//checks whether a bomb/defusal kit can be placed at the given column number
bool ConnectBombBoard::isBombPlaceable(int column_number){
    if(cells[0][column_number].getColor() == Constants::EMPTY){
        return true;
    }
    else{
        return false;
    }
}

//Constructor with the starting player as parameter
ConnectBombBoard::ConnectBombBoard(string player){
    //cout << "Game Board Created with first play by " << player << endl;
    for(int i = 0; i < Constants::ROWS; i++){
        for(int j = 0; j < Constants::COLUMNS; j++){
            cells[i][j].row = i;
            cells[i][j].column = j;
        }
    }
    lastmove.row = -1;
    lastmove.column = -1;
    lastmove.color = Constants::EMPTY;
    ofstream ofs;
    ofs.open("moves.json", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    fstream f(Constants::filename.c_str(),ios::in | ios::out);
    f << "{\n\t\"moves\" : [\n";
    f.close();
}

//Get the position of the last bomb dropped into the board
BombCell ConnectBombBoard::getLastMove(){
    return lastmove;
}

//Get the Color of the cell at (row,column)
char ConnectBombBoard::getCellColor(int row,int column){
    return cells[row][column].getColor();
}

//Drops the bomb in the "column" if it is a valid move
void ConnectBombBoard::dropBomb(int column,char color,string player){
    //cout << "Trying to place bomb at " << column << " column by " << player << endl;
    if(isBombPlaceable(column)){
        //cout << "Bomb Placed" << endl;
        int row = Constants::ROWS-1;
        while(cells[row][column].color != Constants::EMPTY) row--;
        cells[row][column].color = color;
        char l = lastmove.color;
        lastmove.row = row;
        lastmove.column = column;
        lastmove.color = color;
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        if(l != Constants::EMPTY)
            f << ",\n";
        f << "\t\t{\n\t\t\t\"player\" : \"" << player << "\",\n"<< "\n\t\t\t\"row\" : \"" << row << "\",\n"<< "\n\t\t\t\"column\" : \"" << column << "\"\n"<< "\t\t}";
        f.close();
    }
    else{
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"winner\" : \" " << ((player == Constants::userbotname) ? Constants::compbotname : Constants::userbotname) << "\"\n}";
        f.close();
        exit(0);
    }
}
