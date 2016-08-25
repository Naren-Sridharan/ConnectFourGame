#include <string>
using namespace std;
#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

class Constants{
    public:
    //name of computer bot
    static std::string const compbotname;

    //name of contestant's bot
    static std::string const userbotname;

    //JSON file that is created
    static std::string const filename;

    //Number of Rows in board
    static const int ROWS = 6;

    //Number of Columns in board
    static const int COLUMNS = 7;

    //colors used
    enum NuclearCellStatus{
        BOMB,
        DEFUSER,
        EMPTY
    };

    enum PlayerType{
    USER,
    COMP
    };
};

std::string const Constants::filename = "moves.json";
std::string const Constants::compbotname = "defuser";
std::string const Constants::userbotname = "bomber";

#endif // CONSTANTS_H;
