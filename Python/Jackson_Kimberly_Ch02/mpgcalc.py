# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 2, Exercise 7 - MPG Calculator - 8/29/13
# Description: Calculate the fuel efficiency of a car using the formula
# MPG = miles driven/gallons used. Ask user for number of miles driven and
# gallons of gas used.
fuelUsed = float(input('Please enter the number of gallons used: '))
milesDriven = float(input('Now enter the number of miles driven: '))
mpg = milesDriven/fuelUsed
print('Your fuel efficiency is', format(mpg, '2.1f'), 'miles per gallon.')
