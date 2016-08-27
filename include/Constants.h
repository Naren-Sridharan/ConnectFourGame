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

#endif // CONSTANTS_H;
