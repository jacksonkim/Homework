# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, Employee Dictionary - 11/22/13
# Description: Write a program that uses the Employee class
# and holds the data in the book. Add that Employee data
# to a dictionary using the ID Number as the key. The program
# should have the following menu:
# Look up employee
# Add new employee
# Change an existing employee
# Delete employee
# Quit. the program, not the job

# when the program ends, it should pickle the dictionary and
# save it to a file. if there is no file, empty dictionary

#this is gonna take a while...

#gotta import the class we're using based on filename
#and find the pickle
import employee
import pickle

#menu options
LOOKUP = 1
ADD = 2
CHANGE = 3
DELETE = 4
QUIT = 5

#filename
FILENAME = 'employees.dat'

#main function
def main():
    #load the existing employee dictionary
    employees = load_emps()

    #init variable for user's options
    choice = 0

    #process menu selections
    while choice != QUIT:

        #get the choice
        choice = getChoice()

        #process choice
        if choice == LOOKUP:
            lookup(employees)
        elif choice == ADD:
            add(employees)
        elif choice == CHANGE:
            change(employees)
        elif choice == DELETE:
            delete(employees)

    #save the employees dictionary to the file
    save_emps(employees)

def load_emps():
    try:
        #open the file
        infile = open(FILENAME, 'rb')

        #depickle
        emp_dic = pickle.load(infile)

        #close the file
        infile.close()
    except IOError:
        #couldn't open the file so empty dictionary
        emp_dic = {}

    #return the dictionary
    return emp_dic

#menu options and choice
def getChoice():
    print()
    print('Menu')
    print('---------------------------')
    print('1. Look up an employee')
    print('2. Add a new employee')
    print('3. Change an existing employee')
    print('4. Delete an employee')
    print('5. Quit')
    print()

    #accept choice
    choice = int(input('Enter in the number of your choice: '))

    #validate
    while choice < LOOKUP or choice > QUIT:
        choice = int(input('Enter in the valid number of your choice: '))

    #if we got here, you made it
    return choice

#find an existing employee
def lookup(emps):
    #get the ID to look up
    idnum = input('Enter in a valid ID number: ')

    #validate
    while len(idnum) > 5 or len(idnum) < 5:
        idnum = input('Enter in a valid ID number: ')

    #look that stuff up
    print(emps.get(idnum, 'That employee ID was not found.'))

#add function adds a new entry
def add(emps):
    #get the information, obviously
    name = input('Enter in the employee\'s name: ')
    idnum = input('Enter in the employee\'s ID number: ')
    dep = input('Enter in the employee\'s department: ')
    title = input('Enter in the employee\'s title: ')

    #validate
    while len(idnum) > 5 or len(idnum) < 0:
        idnum = input('Enter in a valid ID number: ')
    
    
    #generate an employee object
    newguy = employee.Employee()
    #since this object doesn't set all at instantiation
    newguy.setAll(name, idnum, dep, title)

    verify = 'n'
    #verify the information
    while verify != 'y':
        print(newguy)
        print('Is the above information correct?')
        verify = input('Enter y for yes: ')
        if verify != 'y':
            name = input('Enter in the employee\'s name: ')
            idnum = input('Enter in the employee\'s ID number: ')
            dep = input('Enter in the employee\'s department: ')
            title = input('Enter in the employee\'s title: ')

            #validate
            while len(idnum) > 5 or len(idnum) < 0:
                idnum = input('Enter in a valid ID number: ')

    #verify that the idnumber does not exist in the dictionary
    #add it as a key with the employee object as the associated value
    if idnum not in emps:
        emps[idnum] = newguy
        print('The employee has been added.')
    else:
        print('That ID number is already in use.')

#alterations changes an existing entry
def change(emps):
    #get the idnumber
    idnum = input('Enter in a valid ID number: ')

    #validate
    while len(idnum) > 5 or len(idnum) < 5:
        idnum = input('Enter in a valid ID number: ')
    
    #find it
    if idnum in emps:
        #get the new information
        name = input('Enter in the employee\'s new name: ')
        dep = input('Enter in the employee\'s new department: ')
        title = input('Enter in the employee\'s new title: ')

        #generate an employee object
        newguy = employee.Employee()
        #since this object doesn't set all at instantiation
        newguy.setAll(name, idnum, dep, title)

        verify = 'n'
        #verify the information
        while verify != 'y':
            print(newguy)
            print('Is the above information correct?')
            verify = input('Enter y for yes: ')
            if verify != 'y':
                name = input('Enter in the employee\'s name: ')
                dep = input('Enter in the employee\'s department: ')
                title = input('Enter in the employee\'s title: ')
                
        #update
        emps[idnum] = newguy
        print('The employee has been updated.')
    else:
        print('That ID number was no found.')

#delete removes an entry
def delete(emps):
    #get the idnumber
    idnum = input('Enter in a valid ID number: ')

    #validate
    while len(idnum) > 5 or len(idnum) < 5:
        idnum = input('Enter in a valid ID number: ')
        
    #find it
    if idnum in emps:
        #this won't work for some reason
        #verify = 'y'
        #verify the information
        #while verify != 'y':
            #print(newguy)
            #print('Is the above information correct?')
            #verify = input('Enter y for yes: ')
            #if verify != 'y':
        #it'll work now, but not with the rest.
        del emps[idnum]
        print('Employee fired.')
    else:
        print('That ID number was not found.')

#pickling to the file
def save_emps(emps):
    #open the file for output
    outfile = open(FILENAME, 'wb')

    #pickle the dictionary
    pickle.dump(emps, outfile)
    #how am i not making sex jokes

    #close the file
    outfile.close()

#FINALLY WE CAN RUN IT
main()
