# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, CashRegister Class - 12/09/13
# Description: Allow a user to buy the stuff from the RetailItems class
# via a menu driven system. Once the user is ready to check out,
# display the items for purchase and the total price.
# And then something. Unspecified.

import RetailItem
import CashRegister

register1 = CashRegister.CashRegister()

ret1 = RetailItem.RetailItem()
ret2 = RetailItem.RetailItem()
ret3 = RetailItem.RetailItem()

ret1.setAll('Jacket', 12, 59.95)
ret2.setAll('Designer Jeans', 40, 34.95)
ret3.setAll('Shirt', 20, 24.95)

def main():    

    menuoption = int(0)

    while menuoption != 3:
        print('\n1. Add item')
        print('2. Check out')
        print('3. Quit')

        menuoption = int(input('Which would you like to do? '))

        if menuoption == 1:
            additem()
        elif menuoption == 2:
            checkout()

    print('\nThanks.')


def additem():
    menuoption = int(0)
    while menuoption != 4:
        print('\n1. ', ret1)
        print('2. ', ret2)
        print('3. ', ret3)
        print('4. Quit')

        menuoption = int(input('\nWhich would you like to purchase? '))

        if menuoption == 1:
            register1.purchase_item(ret1)
        elif menuoption == 2:
            register1.purchase_item(ret2)
        elif menuoption == 3:
            register1.purchase_item(ret3)

def checkout():
    print('\n\nTotal is: $', format(register1.get_total(), '.2f'))
    print('\nThank you.')

main()
