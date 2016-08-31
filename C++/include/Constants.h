#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>
using namespace std;
class Constants{
    public:
    //name of computer bot
    static std::string const compbotname;

    //name of contestant's bot
    static std::string const userbotname;

    //Number of Rows in board
    static const int ROWS = 6;

    //Number of Columns in board
    static const int COLUMNS = 7;

    //colors used
    enum NuclearCellStatus{
        BOMB,
        DEFUSER,
        EMPTY,
        INVALID
    };

    enum PlayerType{
    USER,
    COMP,
    NOPLAYER
    };
};

#endif // CONSTANTS_H;
