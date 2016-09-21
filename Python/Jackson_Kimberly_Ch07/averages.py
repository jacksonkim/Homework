# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 7, Law of Averages - 10/10/13
# Description: Read all the integers from a file and
# generate an average based on the numbers.

def main():
    readfile = open('numbers.txt', 'r')
    timesread = 0
    nums = int(readfile.readline())
    while(nums != ''):
        timesread += 1
        nums2 = readfile.readline()

        if(nums2 == ''):
            break
        else:
            nums2 = int(nums2)
            nums += nums2
    
    print("The average of all numbers in the file is", format(nums/timesread, '.1f'))

    readfile.close()


#execute
main()
