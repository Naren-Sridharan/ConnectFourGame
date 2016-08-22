#ifndef BOMBCELL_H_INCLUDED
#define BOMBCELL_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Constants.h"

//Cell in a board
class BombCell{
    // row and column of the cell
    int row,column;
    friend class ConnectBombBoard;
    friend class GameController;
    // color of cell indicating whether it is empty or a bomb is placed
    char color;


    public:
    //constructor
    BombCell();

    //Get the row number of the cell
    int getRow();

    //Get the column number of the cell
    int getColumn();

    //Get the Color of the cell
    char getColor();

};


#endif // BOMBCELL_H_INCLUDED
