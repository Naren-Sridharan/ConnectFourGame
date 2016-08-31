from Constants import Constants

class NuclearCell:
    def __init__(self):
        self.__row = -1
        self.__column = -1
        self.__status = Constants.NuclearCellStatus.EMPTY

    def getRowIndex(self):
        return self.__row
    
    def getColumnIndex(self):
        return self.__column
    
    def getStatus(self):
        return self.__status

    def setRowIndex(self,row):
        self.__row = row

    def setColumnIndex(self,column):
        self.__column = column

    def setStatus(self,status):
        self.__status = status

    
