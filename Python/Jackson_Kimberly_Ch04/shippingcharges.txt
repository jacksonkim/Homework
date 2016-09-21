# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 4, Shipping Charges - 9/18/13
# Description: Ask user for the weight of a package and display the shipping
# charge based on the weight as pertaining to this chart.
# if < 2pounds 1.10 per pound
# < 6pounds 2.20 per pound
# < 10pounds 3.70 per pound
# > 10pounds 3.80 per pound

def calculations(pounds):
    if pounds <= 2.0:
        return pounds * 1.10
    elif pounds <= 6.0:
        return pounds * 2.20
    elif pounds <= 10.0:
        return pounds * 3.7
    elif pounds > 10.0:
        return pounds * 3.80

def main():
    pounds = float(input("Please enter in the numerical value of the weight of your package: "))
    charges = calculations(pounds)
    print("The cost to ship this package will be $", format(charges, ".2f"),".")

#execute main
main()
