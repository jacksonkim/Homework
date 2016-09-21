# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 5, Staircase - 9/19/13
# Description: Make a program that makes a staircase of #

NUM_STEPS = 6

for r in range(NUM_STEPS):
    print('#', end='')
    for c in range(r):
        print(' ', end='')
    print('#')
