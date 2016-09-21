# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 6, Random Math Quiz - 10/3/13
# Description: Generate math random math problems. Allow the user
# to enter a number as an answer. If the answer is correct, display
# a message of congrats. If not, display the correct answer.

#we need random numbers, so obviously import the random module
import random

# gotta save the random number somewhere so they remain
# static
num1 = random.randint(1,1000)
num2 = random.randint(1,1000)
answernum = num1+ num2

print(" ", num1)
print("+", num2)
print("-----")
usernum = int(input("Enter in the numerical correct value: "))

if (usernum == answernum):
    print("Good job!")
else:
    print("Sorry. The correct answer was:", answernum)
