# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 7, File Head Display - 10/6/13
# Description: Ask the user for the name of a file. This file name
# is then used to read the first 5 lines of that file. If it is
# less than 5 lines, the entire contents.

def main():
    
    print("(The name of the file to open is stories.txt)")
    finame = input("Please type in the name of the file you would like to open: ")
    #make sure the file can open
    try:
        infile = open(finame, 'r')
    #if the file opens, read from it
        for lines in range(5):
            words = infile.readline()
            print(words)

        infile.close()
    except IOError:
        print("An error occurred trying to read from file", finame, ".")
    

#execute
main()
