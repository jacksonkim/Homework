# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, CashRegister Class - 12/09/13
# Description: Create a CashRegister class that holds the following
# List of RetailItem objects
# purchase_item: accepts RetailItem, adds it to the list
# get_total: returns total price of all the RetailItem objects in the list
# show_items: displays data about the RetailItems in the list
# clear: clear the RetailItems list

import RetailItem

class CashRegister:

    def __init__(self):
        self.items = []

    def purchase_item(self, i):
        self.items.append(i)
        
    def showitems(self):
        for self.thing in self.items:
            print(self.thing)

    def get_total(self):
        self.total = float(0.0)
        for self.thing in self.items:
            self.total = self.total + self.thing.getPrice()
        return self.total

    def clear(self):
        del self.items
