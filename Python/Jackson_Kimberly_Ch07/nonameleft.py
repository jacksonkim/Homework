# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 7, No Name Left Behind - 10/10/13
# Description: Read all entries in a file named
# names.txt

def main():
    readfile = open('names.txt', 'r')
    timesread = 0
    name = readfile.readline()
    while(name!=''):
        timesread += 1
        name = readfile.readline()
    print("The number of names in the file is", timesread)

    readfile.close()


#execute
main()
