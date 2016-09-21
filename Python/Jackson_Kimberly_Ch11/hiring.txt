# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, Employee Class - 11/20/13
# Description: Write a program that uses the Employee class
# and holds the data in the book.

#gotta import the class we're using based on filename
import employee

#create objects
#the init does not accept any arguments
emp1 = employee.Employee()
emp2 = employee.Employee()
emp3 = employee.Employee()

print('Employee objects created, filling out required information...\n')
#set all the information; there's a method for that!
emp1.setAll('Susan Meyers', '47899', 'Accounting', 'Vice President')
emp2.setAll('Mark Jones', '39119', 'IT', 'Programmer')
emp3.setAll('Joy Rogers', '81774', 'Manufacturing', 'Engineer')

print('Employee information filed, displaying all employees created...\n')
#there is also a method for printing already formatted
#emp1.printAll()
#emp2.printAll()
#emp3.printAll()

#or i could overload the string method
print(emp1)
print(emp2)
print(emp3)

print('Employee information displayed. Closing program...')
