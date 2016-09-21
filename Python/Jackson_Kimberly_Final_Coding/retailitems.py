# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, RetailItem Class - 12/09/13
# Description: Create a program that loads the RetailItem class
# with the following:
# Jacket - 12 - 59.95
# Designer Jeans - 40 - 34.95
# Shirt - 20 - 24.95

import RetailItem

ret1 = RetailItem.RetailItem()
ret2 = RetailItem.RetailItem()
ret3 = RetailItem.RetailItem()

ret1.setAll('Jacket', 12, 59.95)
ret2.setAll('Designer Jeans', 40, 34.95)
ret3.setAll('Shirt', 20, 24.95)

print(ret1)
print(ret2)
print(ret3)
