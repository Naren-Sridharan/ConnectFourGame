#include "NuclearCell.h"
//Get the row number of the cell
int NuclearCell::getRowIndex(){
    return row;
}

//Get the column number of the cell
int NuclearCell::getColumnIndex(){
    return column;
}

//Get the Color of the cell

Constants::NuclearCellStatus NuclearCell::getStatus(){
    return status;
}
