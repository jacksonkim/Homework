# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 5, Distance Calculator - 9/19/13
# Description: Ask the user for the speed and amount of time
# traveling at that speed and then display, incrementally,
# the total distance traveled.

def main():
    print("This program will be using only whole numbers. No decimals.")
    print("(I'm watching you...)")
    speed = int(input("Please enter in the speed in miles per hour: "))
    maxtime = int(input("Please enter the amount of hours traveled: "))
    incrementTime = 0
    incrementDist = 0
    print("Hours/tDistance")
    while (incrementTime != maxtime):
        incrementTime += 1
        incrementDist = speed*incrementTime
        print(incrementTime, "\t", incrementDist)

#execute
main()
