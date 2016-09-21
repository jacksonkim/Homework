# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 6, G Force - 10/3/13
# Description: Write a function called falling_distance
# that accepts the time falling as seconds and diplays
# the distance fallen. Write a loop that sends 1-10 as seconds.
# Formula: d = .5(g*t^^2)
# g = 9.8meters

def falling_distance(seconds):
    distance = float(0.5*(9.8*(seconds**2)))
    return distance

for count in range(10):
    print("Distance traveled in", count+1, "seconds: ", end="")
    print(format(falling_distance(count+1), '.2f'), "meters.")
