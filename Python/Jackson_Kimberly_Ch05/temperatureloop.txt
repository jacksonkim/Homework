# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 5, Temperature Loop - 9/19/13
# Description: Display Celsius 0 - 20 and its Fahrenheit equivalent

print("Celsius\tFahrenheit")
for number in range(0, 21):
    fahren = (9/5*number)+32
    print(number, "\t", format(fahren, ".1f"))
