from NuclearCell import NuclearCell
from Constants import Constants
class Move:
    player = ''
    row = 0
    column = 0
    
class Point:
    row = 0
    column = 0

moves = list()
FinalPoints = list()

def writeToJson(player):
    print "{"
    print '\t"moves" : ['
    for move in moves:
        print "\t\t{"
        print '\t\t\t"player" : "' + move.player + '",'
        print '\t\t\t"row" : "' + str(move.row) + '",'
        print '\t\t\t"column" : "' + str(move.column) + '"'
        print "\t\t}" + ("," if(move is not moves[len(moves)-1]) else '')
    
    print "\t],"
    print '\t"coordinates" : ['

    for FinalPoint in FinalPoints:
        print "\t\t{"
        print '\t\t\t"row" : "' + str(FinalPoint.row) + '",'
        print '\t\t\t"column" : "' + str(FinalPoint.column) + '"'
        print "\t\t}" + ("," if(FinalPoint is not FinalPoints[len(FinalPoints) - 1]) else "")

    print"\t],"
    print '\t"winner" : "' + player + '"'
    print "}"
    
class NuclearReactor:
    def __init__(self):
        self.__cells = list()
        for i in range(Constants.ROWS):
            rowcell = list()
            for j in range(Constants.COLUMNS):
                cell = NuclearCell()
                cell.setRowIndex(i)
                cell.setColumnIndex(j)
                rowcell.append(cell)
            self.__cells.append(rowcell)
        self.__lastmove = NuclearCell()

    def getRecentOpponentMove(self):
        return self.__lastmove

    def isBombPlaceable(self,column_number):
        if(self.__cells[0][column_number].getStatus() == Constants.NuclearCellStatus.EMPTY):
            return True
        else:
            return False
        
    def dropBomb(self,column,P):
        if(self.isBombPlaceable(column)):
            row = Constants.ROWS-1
            while(self.__cells[row][column].getStatus() is not Constants.NuclearCellStatus.EMPTY):
                row -= 1
            self.__cells[row][column].setStatus(Constants.NuclearCellStatus.BOMB if P else Constants.NuclearCellStatus.DEFUSER)
            self.__lastmove.setRowIndex(row)
            self.__lastmove.setColumnIndex(column)
            self.__lastmove.setStatus(self.__cells[row][column].getStatus())
            move = Move()
            move.player = Constants.userbotname if P else Constants.compbotname
            move.row = row
            move.column = column
            moves.append(move)
        else:
            #print 'invalid move'
            writeToJson(Constants.userbotname if P else Constants.compbotname)
            exit(0)
       
    def getCellStatus(self,row,column):
        try:
            return self.__cells[row][column].getStatus()
        except:
            return Constants.Constants.NuclearCellStatus.INVALID      

    def isGameOver(self):
        directions = [0]*8
        flags = [False]*8
        n = 0
        row = self.__lastmove.getRowIndex()
        column = self.__lastmove.getColumnIndex()
        status = self.__lastmove.getStatus()

        if( row == -1 and column == -1):
            return Constants.PlayerType.NOPLAYER

        for i in range(3):
            for j in range(8):
                if(directions[j] == i and flags[j] is False):
                    if(j == 0):
                        if(row-i-1 >= 0 and row-i-1 < Constants.ROWS  and column-i-1 >=0 and column-i-1 < Constants.COLUMNS):
                            if(self.getCellStatus(row-i-1,column-i-1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 1):
                        if(row-i-1 >= 0 and row-i-1 < Constants.ROWS):
                            if(self.getCellStatus(row-i-1,column) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 2):
                        if(row-i-1 >= 0 and row-i-1 < Constants.ROWS  and column+i+1 >=0 and column+i+1 < Constants.COLUMNS):
                            if(self.getCellStatus(row-i-1,column+i+1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 3):
                        if(column+i+1 >=0 and column+i+1 < Constants.COLUMNS):
                            if(self.getCellStatus(row,column+i+1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 4):
                        if(row+i+1 >= 0 and row+i+1 < Constants.ROWS  and column+i+1 >=0 and column+i+1 < Constants.COLUMNS):
                            if(self.getCellStatus(row+i+1,column+i+1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 5):
                        if(row+i+1 >= 0 and row+i+1 < Constants.ROWS):
                            if(self.getCellStatus(row+i+1,column) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    elif(j == 6):
                        if(row+i+1 >= 0 and row+i+1 < Constants.ROWS  and column-i-1 >=0 and column-i-1 < Constants.COLUMNS):
                            if(self.getCellStatus(row+i+1,column-i-1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True
                    else:
                        if(column-i-1 >=0 and column-i-1 < Constants.COLUMNS):
                            if(self.getCellStatus(row,column-i-1) is status):
                                directions[j] += 1
                            else:
                                flags[j] = True

        if((directions[0]+directions[4]) >= 3 or (directions[1]+directions[5]) >= 3 or (directions[2]+directions[6]) >= 3 or (directions[3]+directions[7]) >= 3):
            if((directions[0]+directions[4]) >= 3):
                i = 0;
                for j in range(directions[0]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row - 1 - j
                    point.column = column - 1 - j
                    FinalPoints.append(point)
                    i += 1
                for j in range(directions[4]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row + 1 + j
                    point.column = column + 1 + j
                    FinalPoints.append(point)
                    i += 1
            elif((directions[1]+directions[5]) >= 3):
                i = 0;
                for j in range(directions[1]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row - 1 - j
                    point.column = column
                    FinalPoints.append(point)
                    i += 1
                for j in range(directions[5]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row + 1 + j
                    point.column = column
                    FinalPoints.append(point)
                    i += 1
            elif((directions[2]+directions[6]) >= 3):
                i = 0;
                for j in range(directions[2]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row - 1 - j
                    point.column = column + 1 + j
                    FinalPoints.append(point)
                    i += 1
                for j in range(directions[6]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row + 1 + j
                    point.column = column - 1 - j
                    FinalPoints.append(point)
                    i += 1
            else:
                i = 0;
                for j in range(directions[3]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row
                    point.column = column + 1 + j
                    FinalPoints.append(point)
                    i += 1
                for j in range(directions[7]):
                    if(i>=3):
                        break
                    point = Point()
                    point.row = row
                    point.column = column - 1 - j
                    FinalPoints.append(point)
                    i += 1
            point = Point()        
            point.row = row
            point.column = column
            FinalPoints.append(point)
                
            return (Constants.PlayerType.COMP if status else Constants.PlayerType.USER)
        else:
            for k in range(Constants.COLUMNS):
                n += 1
                if(self.isBombPlaceable(k)):
                    break;
            if( n == Constants.COLUMNS):
                print '\t"winner" : "draw"'
                print '}'
                exit(0)
            return Constants.PlayerType.NOPLAYER
