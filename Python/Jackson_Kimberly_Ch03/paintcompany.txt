# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 3, Paint Company - 9/5/13
# Description: Ask a user for the square footage of wall space to paint
# and price per gallon of paint.
# 115sq ft = 1gallon of paint & 8 hours of work
# 1hr of work = $20
# Cannot have a partial gallon of paint to purchase, but can work
# less hours than the gallon of paint. Round up paint gallons?

#import math for rounding up
import math

#global constant for the base calculation
BASE_SQFT = 115

#Calculate paint gallons to the next highest
def gallonEstimate(sqft):
    paintgallons = math.ceil(sqft/BASE_SQFT)
    return paintgallons

#calc hours of work
def laborEstimate(sqft):
    paintgallons = sqft/BASE_SQFT
    labor = paintgallons*8
    return labor

#calc cost for work
def laborCost(hours):
    return hours*20

#calc cost of paint
def paintCost(gallons, paintp):
    return gallons*paintp

#calc total cost of everything
def totalEstimate(hours, paintprice):
    return hours+paintprice

#main IO function
def main():
    sqfeet = float(input('Please input the numerical only amount of square foot to paint: '))
    paintPrice = float(input('Please input the numerical only cost of a gallon of paint: '))
    gallons = gallonEstimate(sqfeet)
    laborHours = laborEstimate(sqfeet)
    paintcost = paintCost(gallons, paintPrice)
    laborcost = laborCost(laborHours)    
    print('\nThe total number of paint used for', sqfeet, ' will be', gallons, 'gallons of paint.')
    print('This paint will cost about $', format(paintcost, '2.1f'), '.')
    print('The whole job should take', format(laborHours, '2.0f'), 'hours to complete.')
    print('Which will cost $', format(laborcost, '2.2f'), '.')
    print("So for the paint and the labor, you're looking at $", format(totalEstimate(paintcost, laborcost), '2.2f'), ".")

#call the main to execute
main()
