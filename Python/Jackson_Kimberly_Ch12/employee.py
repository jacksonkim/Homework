# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 11, Employee Class - 11/20/13
# Description: Write a class named Employee that holds the
# following data: name, ID, department, and title

class Employee:

    # set everything to blank    
    def __init__(self):
        self.name = ''
        self.idnum = ''

    #set everything individually
        #name
    def setName(self, n):
        self.name = n

        #idnumber of employee
    def setIDNum(self, idn):
        self.idnum = idn

        #department they work in
    def setDepartment(self, dep):
        self.department = dep

        #employee's job title
    def setTitle(self, t):
        self.title = t
        
        #set all of them at the same time
    def setAll(self, n, idn, dep, t):
        self.name = n
        self.idnum = idn
        self.department = dep
        self.title = t

    #return everything individually
    def getName(self):
        return self.name

        #idnumber of employee
    def getIDNum(self):
        return self.idnum

        #department they work in
    def getDepartment(self):
        return self.department

        #employee's job title
    def getTitle(self):
        return self.title
        
        #get all of them at the same time
    #def getAll(self, n, idn, dep, t):
        #self.name = n
        #self.idnum = idn
        #self.department = dep
        #self.title = t

    #print out everything
    def printAll(self):
        print('Employee Name:', self.name)
        print('Employee ID Number:', self.idnum)
        print('Department:', self.department)
        print('Employee Title:', self.title)
        print()

    def __str__(self):
        return 'Employee Name: ' + self.name + \
               '\nEmployee ID Number: ' + self.idnum + \
               '\nDepartment: ' + self.department + \
               '\nEmployee Title: ' + self.title + "\n"
