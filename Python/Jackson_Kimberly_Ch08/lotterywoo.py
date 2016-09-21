# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 9?, Lottery Generator, 10/29/13
# Description: Randomize a 7 digit lottery number, limited to
# 0-9, and assign to a List. Display via loop.

import random

#cut down on stuff in the list, just utilize a function
def randomize():
    return random.randint(0, 9)

#main functionality
def main():
    lotterynums = [randomize(), randomize(), randomize(),
                   randomize(), randomize(), randomize(), randomize()]

    print("Lottery numbers this week: ", end="")

    for nums in range(8):
        print(" |", lotterynums[nums-1], end="")

    print(" |")
    print("Didja win?")

#execute main
main()
