# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 6, Extrapolate Future Value - 10/3/13
# Description: Accept user's input of their account's current value,
# monthly interest rate, and the number of months the money will be
# left in the account untouched. Pass these values to a function and
# return the future value after the specified number of months.
# Formula: F = P*(1+i)^t
# F = Future value
# P = Present value
# i = monthly interest rate
# t = number of months

#formula function
def futuremuns(curmuns, interest, months):
    return curmuns*(1+interest)**months

def main():
    #get the required input
    currentmuns = float(input("Please input the current numerical value of your account: $"))
    rate = float(input("And the interest rate: "))
    rate = rate/100 #convert to decimal
    months = int(input("Lastly, the whole number of months that we will let this money ferment: "))

    #calculate
    futuremunnies = futuremuns(currentmuns, rate, months)
    print("\nEstimated future value of this account $", end="")
    print(format(futuremunnies, ".2f"))

#execute
main()
