/*<<<<<<< HEAD:src/NuclearReactor.cpp
#include "NuclearReactor.h"

//checks whether a bomb/defusal kit can be placed at the given column number
bool NuclearReactor::isBombPlaceable(int column_number){
    if(cells[0][column_number].getStatus() == Constants::EMPTY){
        return true;
    }
    else{
        return false;
    }
}

//CopyConstructor
        NuclearReactor::NuclearReactor(NuclearReactor const &NR){
            for(int i = 0; i < Constants::ROWS; i++)
                for(int j = 0; j < Constants::COLUMNS; j++)
                    this->cells[i][j] = NR.cells[i][j];
            this->lastmove = NR.lastmove;
        }

//Constructor with the starting player as parameter
NuclearReactor::NuclearReactor(){
    //cout << "Game Board Created with first play by " << player << endl;
    for(int i = 0; i < Constants::ROWS; i++){
        for(int j = 0; j < Constants::COLUMNS; j++){
            cells[i][j].setRowIndex(i);
            cells[i][j].setColumnIndex(j);
        }
    }
    lastmove.setRowIndex(-1);
    lastmove.setColumnIndex(-1);
    lastmove.setStatus(Constants::EMPTY);
    ofstream ofs;
    ofs.open("moves.json", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    fstream f(Constants::filename.c_str(),ios::in | ios::out);
    f << "{\n\t\"moves\" : [\n";
    f.close();
}

//Get the position of the last bomb dropped into the board
NuclearCell NuclearReactor::getRecentOpponentMove(){
    return lastmove;
}

//Get the status of the cell at (row,column)
Constants::NuclearCellStatus NuclearReactor::getCellStatus(int row,int column){
    return cells[row][column].getStatus();
}

//Drops the bomb in the "column" if it is a valid move
void NuclearReactor::dropBomb(int column,Constants::PlayerType P){
    //cout << "Trying to place bomb at " << column << " column by " << player << endl;
    if(isBombPlaceable(column)){
        //cout << "Bomb Placed" << endl;
        int row = Constants::ROWS-1;
        while(cells[row][column].getStatus() != Constants::EMPTY) row--;
        cells[row][column].setStatus((P)?Constants::BOMB : Constants::DEFUSER);
        Constants::NuclearCellStatus l = lastmove.getStatus();
        lastmove.setRowIndex(row);
        lastmove.setColumnIndex(column);
        lastmove.setStatus(cells[row][column].getStatus());
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        if(l != Constants::EMPTY)
            f << ",\n";
        f << "\t\t{\n\t\t\t\"player\" : \"" << ((P)?Constants::userbotname : Constants::compbotname) << "\",\n"<< "\n\t\t\t\"row\" : \"" << row << "\",\n"<< "\n\t\t\t\"column\" : \"" << column << "\"\n"<< "\t\t}";
        f.close();
    }
    else{
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"winner\" : \" " << ((P)?Constants::userbotname : Constants::compbotname) << "\"\n}";
        f.close();
        exit(0);
    }
}

//check whether the game is over
GameState NuclearReactor::isGameOver(){
    //cout << "Checking if game is over" << endl;
    int k,directions[8] = {0};
    bool flags[8] = {false};
    NuclearCell bc = lastmove;
    int row = bc.getRowIndex();
    int column = bc.getColumnIndex();
    Constants::NuclearCellStatus status = bc.getStatus();
    for(k = 0; k < Constants::COLUMNS; k++)
        if(isBombPlaceable(k))
            break;
    if(k == Constants::COLUMNS){
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"winner\" : \"Draw\"\n}";
        f.close();
        //cout << "End Play" << endl;
        exit(0);
    }
    if(row == -1 && column == -1)
        return NO_STATE;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            if(directions[j] == i && !flags[j]){
                switch(j){
                    case 0:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS  && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row-i-1,column-i-1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 1:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS){
                            if(getCellStatus(row-i-1,column) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 2:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row-i-1,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 3:
                        if(column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 4:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row+i+1,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 5:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS){
                            if(getCellStatus(row+i+1,column) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 6:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row+i+1,column-i-1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 7:
                        if(column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row,column-i-1) == status){
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
        for(int j = 0; i<3 && j < directions[0]; j++){
            points[i].row = row - 1 - j;
            points[i++].column = column - 1 - j;
        }
        for(int j = 0; i<3 && j < directions[4]; j++){
            points[i].row = row + 1 + j;
            points[i++].column = column + 1 + j;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return WIN;
    }
    else if((directions[1]+directions[5]) >= 3){
        int i = 0;
        for(int j = 0; i<3 && j < directions[1]; j++){
            points[i].row = row - 1 - j;
            points[i++].column = column;
        }
        for(int j = 0; i<3 && j < directions[5]; j++){
            points[i].row = row + 1 + j;
            points[i++].column = column;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return WIN;
    }
    else if((directions[2]+directions[6]) >= 3){
        int i = 0;
        for(int j = 0; i<3 && j < directions[2]; j++){
            points[i].row = row - 1 - j;
            points[i++].column = column + 1 + j;
        }
        for(int j = 0; i<3 && j < directions[6]; j++){
            points[i].row = row + 1 + j;
            points[i++].column = column - 1 - j;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return WIN;
    }
    else if((directions[3]+directions[7]) >= 3){
        int i = 0;
        for(int j = 0; i<3 && j < directions[3]; j++){
            points[i].row = row;
            points[i++].column = column + 1 + j;
        }
        for(int j = 0; i<3 && j < directions[7]; j++){
            points[i].row = row;
            points[i++].column = column - 1 - j;
        }
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"Final Points\" : \" [\n\t\t";
        for(int j = 0; j < 4; j++ ){
            f << "\n\t\t{\n\t\t\t\"row\" : \"" << points[j][0] << "},\n\t\t\t{\"column\" : \"" << points[j][1] << "}";
        }
        f << "\n\t\t]\n\t]";
        return WIN;
    }
    return NO_STATE;
}
=======*/
#include "NuclearReactor.h"
vector<Move> moves;
vector<Point> FinalPoints;
//checks whether a bomb/defusal kit can be placed at the given column number
bool NuclearReactor::isBombPlaceable(int column_number){
    if(cells[0][column_number].getStatus() == Constants::EMPTY){
        return true;
    }
    else{
        return false;
    }
}

NuclearReactor::NuclearReactor(NuclearReactor const &NR){
            for(int i = 0; i < Constants::ROWS; i++)
                for(int j = 0; j < Constants::COLUMNS; j++)
                    this->cells[i][j] = NR.cells[i][j];
            this->lastmove = NR.lastmove;
}

//Constructor with the starting player as parameter
NuclearReactor::NuclearReactor(Constants::PlayerType player){
    //cout << "Game Board Created with first play by " << player << endl;
    for(int i = 0; i < Constants::ROWS; i++){
        for(int j = 0; j < Constants::COLUMNS; j++){
            cells[i][j].setRowIndex(i);
            cells[i][j].setColumnIndex(j);
        }
    }
    lastmove.setRowIndex(-1);
    lastmove.setColumnIndex(-1);
    lastmove.setStatus(Constants::EMPTY);
    ofstream ofs;
    ofs.open(Constants::filename.c_str(), std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

//Get the position of the last bomb dropped into the board
NuclearCell NuclearReactor::getRecentOpponentMove(){
    return lastmove;
}

//Get the status of the cell at (row,column)
Constants::NuclearCellStatus NuclearReactor::getCellStatus(int row,int column){
    return cells[row][column].getStatus();
}

//Drops the bomb in the "column" if it is a valid move
void NuclearReactor::dropBomb(int column,Constants::PlayerType P){
    //cout << "Trying to place bomb at " << column << " column by " << player << endl;
    if(isBombPlaceable(column)){
        //cout << "Bomb Placed" << endl;
        int row = Constants::ROWS-1;
        while(cells[row][column].getStatus() != Constants::EMPTY) row--;
        cells[row][column].setStatus((P)?Constants::BOMB : Constants::DEFUSER);
        lastmove.setRowIndex(row);
        lastmove.setColumnIndex(column);
        lastmove.setStatus(cells[row][column].getStatus());
        Move move;
        move.player = ((P)?Constants::userbotname : Constants::compbotname);
        move.row = row;
        move.column = column;
        moves.push_back(move);
    }
    else{
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        writeToJson((P)?Constants::userbotname : Constants::compbotname);
        exit(0);
    }
}

//check whether the game is over
GameState NuclearReactor::isGameOver(){
    //cout << "Checking if game is over" << endl;
    int k,directions[8] = {0};
    bool flags[8] = {false};
    NuclearCell bc = lastmove;
    int row = bc.getRowIndex();
    int column = bc.getColumnIndex();
    Constants::NuclearCellStatus status = bc.getStatus();
    for(k = 0; k < Constants::COLUMNS; k++)
        if(isBombPlaceable(k))
            break;
    if(k == Constants::COLUMNS){
        fstream f(Constants::filename.c_str(),ios::in | ios::out | ios::app);
        f << "],\n\t\"winner\" : \"Draw\"\n}";
        f.close();
        //cout << "End Play" << endl;
        exit(0);
    }
    if(row == -1 && column == -1)
        return NO_STATE;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            if(directions[j] == i && !flags[j]){
                switch(j){
                    case 0:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS  && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row-i-1,column-i-1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 1:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS){
                            if(getCellStatus(row-i-1,column) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 2:
                        if(row-i-1 >= 0 && row-i-1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row-i-1,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 3:
                        if(column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 4:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column+i+1 >=0 && column+i+1 < Constants::COLUMNS){
                            if(getCellStatus(row+i+1,column+i+1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 5:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS){
                            if(getCellStatus(row+i+1,column) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 6:
                        if(row+i+1 >= 0 && row+i+1 < Constants::ROWS && column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row+i+1,column-i-1) == status){
                                directions[j]++;
                            }
                            else{
                                flags[j] = ~flags[j];
                            }
                        }
                        break;
                    case 7:
                        if(column-i-1 >=0 && column-i-1 < Constants::COLUMNS){
                            if(getCellStatus(row,column-i-1) == status){
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
    Point points[4];
    if((directions[0]+directions[4]) >= 3 || (directions[1]+directions[5]) >= 3 || (directions[2]+directions[6]) >= 3 || (directions[3]+directions[7]) >= 3){
       if((directions[0]+directions[4]) >= 3){
            int i = 0;
            for(int j = 0; i<3 && j < directions[0]; j++){
                points[i].row = row - 1 - j;
                points[i++].column = column - 1 - j;
            }
            for(int j = 0; i<3 && j < directions[4]; j++){
                points[i].row = row + 1 + j;
                points[i++].column = column + 1 + j;
            }
        }
        else if((directions[1]+directions[5]) >= 3){
            int i = 0;
            for(int j = 0; i<3 && j < directions[1]; j++){
                points[i].row = row - 1 - j;
                points[i++].column = column;
            }
            for(int j = 0; i<3 && j < directions[5]; j++){
                points[i].row = row + 1 + j;
                points[i++].column = column;
            }
        }
        else if((directions[2]+directions[6]) >= 3){
            int i = 0;
            for(int j = 0; i<3 && j < directions[2]; j++){
                points[i].row = row - 1 - j;
                points[i++].column = column + 1 + j;
            }
            for(int j = 0; i<3 && j < directions[6]; j++){
                points[i].row = row + 1 + j;
                points[i++].column = column - 1 - j;
            }
        }
        else if((directions[3]+directions[7]) >= 3){
            int i = 0;
            for(int j = 0; i<3 && j < directions[3]; j++){
                points[i].row = row;
                points[i++].column = column + 1 + j;
            }
            for(int j = 0; i<3 && j < directions[7]; j++){
                points[i].row = row;
                points[i++].column = column - 1 - j;
            }
        }
        points[3].row = row;
        points[3].column = column;
        for(int j = 0; j < 4 ; j++){
            FinalPoints.push_back(points[j]);
        }
        return WIN;
    }

    return NO_STATE;
}
void writeToJson(string player){
    fstream f(Constants::filename.c_str(),ios::in | ios:: out | ios::app);
    f << "{" << endl;
    f << "\t\"moves\" : [" << endl;
    for(unsigned int i = 0; i < moves.size(); i++){
        f << "\t\t{" << endl;
        f << "\t\t\t\"player\" : \"" << moves[i].player << "\"," << endl;
        f << "\t\t\t\"row\" : \"" << moves[i].row << "\"," << endl;
        f << "\t\t\t\"column\" : \"" << moves[i].column << "\"" << endl;
        f << "\t\t}";
        if(i != moves.size() - 1)
            f << "," << endl;
        else
            f << endl;
    }
    f << "\t]," << endl;

    f << "\t\"Final Points\" : [" << endl;
    for(unsigned int i = 0 ; i < FinalPoints.size(); i++){
        f << "\t\t{" << endl;
        f << "\t\t\t\"row\" : \"" << FinalPoints[i].row << "\"," << endl;
        f << "\t\t\t\"column\" : \"" << FinalPoints[i].column << "\"" << endl;
        f << "\t\t}";
        if(i != FinalPoints.size() - 1)
            f << "," << endl;
        else
            f << endl;
    }
    f << "\t]" << endl;
    f << "}";
    f.close();
}
//>>>>>>> 3a79f7dc034bc0d97e0c2265324f9cbf8b747f78:src/NuclearReactor.cpp
