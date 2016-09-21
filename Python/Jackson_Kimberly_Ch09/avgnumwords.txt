# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 9, Average number of words, 11/5/13
# Description: Accept input from a FILE and count the number
# of words per sentence, then I guess divide that by the number
# of sentences total to reach the average number of words per
# sentence. Whatever.

readfile = open('text.txt', 'r')
line1 = readfile.readline()
line2 = readfile.readline()
line3 = readfile.readline()
line4 = readfile.readline()
line5 = readfile.readline()
line6 = readfile.readline()

line1 = line1.split()
line2 = line2.split()
line3 = line3.split()
line4 = line4.split()
line5 = line5.split()
line6 = line6.split()

total = len(line1) + len(line2) + len(line3) + len(line4) + len(line5) + len(line6)

avg = total/6

print("The average number of words per line is:", format(avg, '.2f'))
