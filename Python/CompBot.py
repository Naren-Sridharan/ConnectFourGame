from Constants import Constants
from Bot import Bot
import random
class CompBot(Bot):
    def __init__(self):
        Bot.__init__(self,Constants.PlayerType.COMP)
        
    def calculateNextMove(self,cb):
        x = random.randint(0,Constants.COLUMNS-1)
        while(cb.isBombPlaceable(x) is False):
            x = random.randint(0,Constants.COLUMNS-1)
        return x
