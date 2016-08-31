#include "ComputerBot.h"
#include "ContestantBot.h"
#include "GameController.h"

//Main to create the game
int main()
{
    UserBot *userBot = new UserBot();
    CompBot * computerBot = new CompBot();
    GameController *gc = new GameController(userBot,computerBot);
    gc->play();
    return 0;
}
