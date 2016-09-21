# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 9, Date Conversion, 11/5/13
# Description: Allow a user to input the date using
# the date format of mm/dd/yyyy which outputs as
# Month dd, year.

date = str(input("Please enter in the date you wish to convert as mm/dd/yyyy: "))
month = date[:2]
month = int(month)

day = date[3:5]
day = int(day)

year = date[6:]
year = int(year)

print("The date entered is ", end='')
if (month == 1):
    print("January ", end='')
elif (month == 2):
    print("February ", end='')
elif (month == 3):
    print("March ", end='')
elif (month == 4):
    print("April ", end='')
elif (month == 5):
    print("May ", end='')
elif (month == 6):
    print("June ", end='')
elif (month == 7):
    print("July ", end='')
elif (month == 8):
    print("August ", end='')
elif (month == 9):
    print("September ", end='')
elif (month == 10):
    print("October ", end='')
elif (month == 11):
    print("November ", end='')
elif (month == 12):
    print("December ", end='')

print(day, end='')
print(',', year)
