def enum(**named_values):
    return type('Enum', (), named_values)
class Constants:
    compbotname = "Defuser"
    userbotname = "bomber"
    ROWS = 6
    COLUMNS = 7
    NuclearCellStatus = enum(BOMB = 0,DEFUSER = 1, EMPTY = 2, INVALID = 3)
    PlayerType = enum(USER = 0,COMP = 1, NOPLAYER = 2)
