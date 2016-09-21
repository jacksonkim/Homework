# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 7, Golfers - 10/10/13
# Description: Allow a user to input information into the
# golf.txt file.

def main():
    print("Time to record this week's scores!")
    stop = 'n'

    golfFile = open('golf.txt', 'a')
    
    while(stop != 'y'):
        golfname = input("Please enter in the player's name: ")
        golfFile.write(golfname + "\n")
        golfscore = int(input("And the whole number only of their score: "))
        golfFile.write(str(golfscore) + "\n")
        stop = input("Would you like to END here? Input 'y' to STOP: ")

    print("I'll keep this info for later.")

    golfFile.close()

#execute
main()
        
