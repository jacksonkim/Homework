# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 7, Know About Golfers - 10/10/13
# Description: Read from the golf.txt and display information.

def main():
    print("The scores you requested:")

    golfFile = open('golf.txt', 'r')

    line = golfFile.readline()

    while(line!=''):
        print(line, end='\t')
        line = int(golfFile.readline())
        print(line)
        line = golfFile.readline()

    golfFile.close()

#execute
main()
