# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 10, Uniqua - 11/14/13
# Description: Read from a file and put all the
# unique words into a set.

infile = open('stories.txt', 'r')

line = infile.readline()
linesplitset = set()
while (line != ''):
    linesplit = line.split()
    linesplitset.update(linesplit)
    line = infile.readline()

infile.close()
print("Following is a list of all of the unique words in the file.\n")
print(linesplitset)

