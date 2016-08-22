#ifndef BOMBBOARD_H_INCLUDED
#define BOMBBOARD_H_INCLUDED
#include "BombCell.h"
//Board for the Game
class ConnectBombBoard{
        BombCell cells[Constants::ROWS][Constants::COLUMNS]; // 2D BOARD made of cells with "ROWS" rows and "COLUMNS" columns
        BombCell lastmove; //Cell on which the last bomb was dropped into
        friend class GameController;
        //Drops the bomb in the "column" if it is a valid move
        void dropBomb(int column,char color,string player);

        //checks whether a bomb/defusal kit can be placed at the given column number
        bool isBombPlaceable(int column_number);

    public:

        //Constructor with the starting player as parameter
        ConnectBombBoard(string player);

        //Get the position of the last bomb dropped into the board
        BombCell getLastMove();

        //Get the Color of the cell at (row,column)
        char getCellColor(int row,int column);


};


#endif // BOMBBOARD_H_INCLUDED
