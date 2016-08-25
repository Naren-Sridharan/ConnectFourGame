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
class NuclearCell{
    // row and column of the cell
    int row,column;
    friend class NuclearReactor;
    friend class GameController;
    // color of cell indicating whether it is empty or a bomb is placed
    Constants::NuclearCellStatus status;


    public:
    //constructor
    NuclearCell();

    //Get the row number of the cell
    int getRowIndex();

    //Get the column number of the cell
    int getColumnIndex();

    //Get the Color of the cell
    Constants::NuclearCellStatus getStatus();

};


#endif // BOMBCELL_H_INCLUDED
