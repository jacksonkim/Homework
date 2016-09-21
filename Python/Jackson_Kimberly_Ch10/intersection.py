# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 10, Uniqua File Analysis - 11/14/13
# Description: Read in two different files and find all
# the unique words. Then find the intersection of those
# different sets.

#process the first file
infile = open('stories.txt', 'r')
line = infile.readline()
linesplitset = set()
while (line != ''):
    linesplit = line.split()
    linesplitset.update(linesplit)
    line = infile.readline()

infile.close()

infile2 = open('dreams.txt', 'r')
line2 = infile2.readline()
linesplitset2 = set()
while (line2 != ''):
    linesplit2 = line2.split()
    linesplitset2.update(linesplit2)
    line2 = infile2.readline()
infile2.close()

linesplitintersect = linesplitset & linesplitset2

print("Following is a list of all of the unique words in both files.\n")
print(linesplitintersect)

