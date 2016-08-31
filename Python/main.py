from CompBot import CompBot
from UserBot import UserBot
from GameController import GameController

userbot = UserBot()
compbot = CompBot()
gc = GameController(userbot,compbot)
gc.play()
