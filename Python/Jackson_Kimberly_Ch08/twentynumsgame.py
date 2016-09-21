# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 9?, Number Analysis, 10/29/13
# Description: Allow a user to enter 20 numbers and store them in a list.
# Peruse through the numbers and display the following:
# Lowest
# Highest
# Total of the numbers
# Average of the numbers

#average out the total
def average(nums):
    notouchy = list(nums)
    total = int(0)
    for steps in range(20):
        total += notouchy[steps]
    return total/20

#find the total and return it
def total(nums):
    notouchy = list(nums)
    total = int(0)
    for steps in range(20):
        total += notouchy[steps]
    return total

#find the highest and return it
def highest(nums):
    notouchy = list(nums)
    highest = notouchy[0]
    for steps in range(20):
        if(highest <= notouchy[steps]):
            highest = notouchy[steps]
    return highest

#find the lowest and return it
def lowest(nums):
    notouchy = list(nums)
    lowest = notouchy[0]
    for steps in range(20):
        if(lowest >= notouchy[steps]):
            lowest = notouchy[steps]
    return lowest

def main():
    print("This program has pauses for input, but entry is optional.")
    print("They occur after the original numbers.\n")
    print("Guess what time it is~")
    print("Time to input TWENTY random numbers.")
    print("Let's get this doooone.")

    numbers = []
    for value in range(20):
        num = int(input("Enter a random number: "))
        numbers.append(num)

    correct = 0
    print("That was arduous, right?")
    print("Bet you don't remember all the things you put in.")
    print("...Oh they're still up there? Well...")
    #print("Which one was the highest though?")
    guess = int(input("Which one was the highest though? "))
    print("It was this one:", highest(numbers))
    print("Didja get it?")
    if(guess == highest(numbers)):
        print("I guess you did. Good job.")
        correct += 1
    #print("How about the lowest? Can't see it now? Take a guess.")
    guess = int(input("How about the lowest? Can't see it now? Take a guess. "))
    print("The lowest was this one:", lowest(numbers))
    print("How about that one, smartypants?")
    if(guess == lowest(numbers)):
        print("Oh you got it? \n\n...Let's move on.")
        correct += 1
    #print("Wanna try your hand at the total of all those random numbers?")
    guess = int(input("Wanna try your hand at the total of all those random numbers?"))
    print("The total of them all was", total(numbers))
    if(guess == total(numbers)):
        print("...Good job.")
        correct += 1
    else:
        print("Oh, you couldn't see them all to total them? Too bad.")
    #print("Since you have that total, try to average them.")
    guess = int(input("Since you have that total, try to average them. "))
    print("The average of all those numbers was", average(numbers))
    if(guess == average(numbers)):
        print("Don't get too excited, I gave that one to you.")
        correct += 1
    print("Did you get any of them?")
    if (correct >= 1):
        print("Oh you did, huh? Guess you want a prize, don't you.")
        print("Well I don't got anything. But hey, grats. \nI guess.")
    print("Don't forget to drop by again.")

#execute
main()
