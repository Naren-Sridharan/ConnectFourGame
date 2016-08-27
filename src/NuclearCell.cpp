#include "NuclearCell.h"
//Get the row number of the cell
int NuclearCell::getRowIndex(){
    return row;
}

//Get the column number of the cell
int NuclearCell::getColumnIndex(){
    return column;
}

void NuclearCell::setColumnIndex(int column){
	this->column = column;
}

void NuclearCell::setRowIndex(int row){
	this->row = row;
}

//Get the Color of the cell

Constants::NuclearCellStatus NuclearCell::getStatus(){
    return status;
}

void NuclearCell::setStatus(Constants::NuclearCellStatus status){
	this->status = status;
}

NuclearCell::NuclearCell(){
}
