# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 5, I see stars - 9/19/13
# Description: Make a program that decrements *****

BASE_SIZE = 8

for r in range(BASE_SIZE, -1, -1):
    for c in range(r+1):
        print('*', end='')
    print()
