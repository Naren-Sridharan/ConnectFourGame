#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED
#include <string>
using namespace std;
class Constants{
    public:
    //name of computer bot
    static std::string const compbotname;

    //name of contestant's bot
    static std::string const userbotname;

    //JSON file that is created
    static std::string const filename = "moves.json";

    //Number of Rows in board
    static const int ROWS = 6;

    //Number of Columns in board
    static const int COLUMNS = 7;

    //colors used
    static const char RED = 'r', BLUE = 'b', EMPTY = 'e';
};

std::string const Constants::filename = "moves.json";
std::string const Constants::compbotname = "defuser";
std::string const Constants::userbotname = "bomber";

#endif // CONSTANTS_H;
