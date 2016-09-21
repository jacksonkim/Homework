# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 4, Time Calculator - 9/18/13
# Description: Ask user for a number of seconds, and then extrapolates
# from there the number of days, hours, minutes, and seconds from that
# number of seconds.
# 60 seconds in a minute
# 3600 seconds in an hour
# 864000 seconds in a day

DAY_SECS = 864000
HOUR_SECS = 3600
MIN_SECS = 60

def main():
    print("So this is a strange program that will take the number of")
    print("seconds from you and convert them into days, hours, minutes,")
    print("and of course, seconds. So first things first.")
    seconds = int(input("Enter in the whole number value of seconds: "))
    days = 0
    hours = 0
    minutes = 0
    while seconds >= 60:
        if seconds >= 864000:
            days = int(seconds/DAY_SECS)
            seconds = seconds%DAY_SECS
        if seconds >= 3600:
            hours = int(seconds/HOUR_SECS)
            seconds = seconds%HOUR_SECS
        if seconds >=60:
            minutes = int(seconds/MIN_SECS)
            seconds = seconds%MIN_SECS
        if hours >=24:
            days = int(hours/24)
            hours = hours%24
        if minutes >=60:
            hours = int(minutes/60)
            minutes = minutes%60
    print(days, "days,", hours, "hours,", minutes, "minutes,", seconds, "seconds")
    
#execute
main()
