# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 4, Dollar Game - 9/17/13
# Description: Ask user for the number of each coin they have
# and if they add up to a whole dollar, they win the game.

def pennies(numofpen):
    return numofpen*.01

def nickels(numofnic):
    return numofnic*.05

def dimes(numofdime):
    return numofdime*.10

def quarters(numofquat):
    return numofquat*.25

def totaler(pen, nic, dime, quat):
    return pen+nic+dime+quat

def main():
    print("This object of this game is to add up the value of a number of coins")
    print("up to a whole dollar. All you have to do is tell me")
    print("the number of coins. So if you have 5 pennies, 3 nickels")
    print("3 dimes, and 2 quarters, we-hell, we have ourselves a whole")
    print("dollar there, kid.")
    #can i actually do this, i wonder
    pens = pennies(int(input("Put in the number of pennies you have: ")))
    nicks = nickels(int(input("Good, good. How about the number of nickels: ")))
    dims = dimes(int(input("Swell. And the number of dimes: ")))
    quatres = quarters(int(input("Almost there, kid, just need the number of quarters: ")))
    #i can. holy crap.
    if totaler(pens, nicks, dims, quatres) == 1.0:
        print("Lessee what we got here...", totaler(pens, nicks, dims, quatres))
        #incoming game grumps references
        print("Good job, kid! What would you like as a prize?")
        print("The (1.) Unicorn Wizard Plush?")
        print("Or maybe the (2.) Mycaruba Noir Film?")
        print("Or what about the (3.) Coal Shoveler's Shovel?")
        prize = int(input("So how about it? 1, 2, or 3?: "))
        if prize == 1:
            print("Excellent choice! Though I always wondered...\nNah, nevermind. Enjoy.")
            #because homophobia is funny, amirite. sigh
        elif prize == 2:
            print("Ooooh, good choice. This is excellently acted and filmed.\nAll black and white.\nYou won't be disappointed.")
            #this commercial is actually really good
        elif prize == 3:
            #oh barry
            print("You want the shovel? Are you sure? It's been said\nthat only the true heir can weild it.")
            print("Well lookit that! Not only did you win the\ngame, but you can weild The Shovel! Spirits be praised...")
            print("That I should have lived long enough to witness this...")
        else:
            print("Nothing, huh? How very noble of you.")
    else:
        #and then firefly reference
        print("Too bad, kid. Guess you weren't burdened with\nan overabundance of schooling.")

#execute main
main()
