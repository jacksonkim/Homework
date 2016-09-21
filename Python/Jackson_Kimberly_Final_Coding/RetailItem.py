# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, RetailItem Class - 12/09/13
# Description: Create a RetailItem class that holds the following
# Item description
# units in inventory
# price

class RetailItem:
    #blank constructor
    def __init__(self):
        self.desc = ''
        self.units = int(0)
        self.price = float(0.0)

    #set everything individually
    def setDesc(self, d):
        self.desc = d

    def setUnit(self, u):
        self.units = u

    def setPrice(self, p):
        self.price = p

    def setAll(self, d,u, p):
        self.desc = d
        self.units = u
        self.price = p

    #return everything individually
    def getDesc(self):
        return self.desc

    def getUnit(self):
        return self.units

    def getPrice(self):
        return self.price

    #print statement
    def __str__(self):
        return 'Item Description: ' + self.desc + '\n' + \
               'Units in Inventory: ' + str(self.units) + '\n' + \
               'Price per unit: $' + str(format(self.price, '.2f')) + '\n'
