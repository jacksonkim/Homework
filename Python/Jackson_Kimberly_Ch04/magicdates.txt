# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 4, Magic Dates - 9/17/13
# Description: Ask user for the two digit month, day, and year of birth
# and then multiply the day by the month. If that number is equal to the
# year of birth, you got a magic date, Lt. Dan.

def main():
    month = int(input("Please enter the two digit numerical value of the month you were born: "))
    day = int(input("And now for the day (same rules apply): "))
    year = int(input("And finally the year (must I remind you of the rules?): "))
    if month*day == year:
        print("Lieutenant Dan, your birthday is magic!")
    else:
        print("Your birthday ain't got no magic, Lieutenant Dan...")

#execute
main()
