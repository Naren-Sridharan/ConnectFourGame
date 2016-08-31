import NuclearReactor
from Bot import Bot
from Constants import Constants
import random
import copy
class GameController:
    def __init__(self,userbot,compbot):
        self.__userbot = userbot
        self.__compbot = compbot
        self.__cb = NuclearReactor.NuclearReactor()
        
        self.__currentPlayer = Constants.PlayerType.USER if(self.__toss()) else Constants.PlayerType.COMP

    def __toss(self):
        return random.randint(0,1)

    def play(self):
        while(self.__cb.getRecentOpponentMove().getStatus() == Constants.NuclearCellStatus.EMPTY or self.__cb.isGameOver() == Constants.PlayerType.NOPLAYER):
            if(self.__currentPlayer == Constants.PlayerType.USER):
                self.__cb.dropBomb(self.__userbot.calculateNextMove(copy.copy(self.__cb)),Constants.PlayerType.USER)
                self.__currentPlayer = Constants.PlayerType.COMP
            else:
                self.__cb.dropBomb(self.__compbot.calculateNextMove(copy.copy(self.__cb)),Constants.PlayerType.COMP)
                self.__currentPlayer = Constants.PlayerType.USER
        NuclearReactor.writeToJson((Constants.compbotname if(self.__currentPlayer) else Constants.userbotname))
    
