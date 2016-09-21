# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 3, Building Insurance Calculator - 9/5/13
# Description: Ask a user for the replacement cost of a building
# and display the minimum amount of property insurance to buy.
# Insurance should be a tleast 80% of the replacement cost.
def percentageCalc(buildCost):
    insurePercent = .8
    result = buildCost*insurePercent
    return result

def main():
    #ask for replacement cost of building
    building = int(input('Please enter the numerical only value of the building: '))
    print('You should purchase at least', percentageCalc(building), 'dollars worth of insurance.')
    

#call the main function to execute
main()
