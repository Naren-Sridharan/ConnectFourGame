<<<<<<< HEAD:include/NuclearCell.h
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
    // color of cell indicating whether it is empty or a bomb is placed
    Constants::NuclearCellStatus status;

    public:
    //constructor
    NuclearCell();

    //Get the row number of the cell
    int getRowIndex();

    //Get the column number of the cell
    int getColumnIndex();

    void setRowIndex(int row);

    void setColumnIndex(int column);

    //Get the Color of the cell
    Constants::NuclearCellStatus getStatus();

    void setStatus(Constants::NuclearCellStatus);

};


#endif // BOMBCELL_H_INCLUDED
=======
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
    // color of cell indicating whether it is empty or a bomb is placed
    Constants::NuclearCellStatus status;

    public:
    //constructor
    NuclearCell();

    //Get the row number of the cell
    int getRowIndex();

    //Get the column number of the cell
    int getColumnIndex();

    void setRowIndex(int row);

    void setColumnIndex(int column);

    //Get the Color of the cell
    Constants::NuclearCellStatus getStatus();

    void setStatus(Constants::NuclearCellStatus);

};


#endif // BOMBCELL_H_INCLUDED
>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78:include/NuclearCell.h
