# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 3, Property Tax Calculator - 9/5/13
# Description: Ask a user for the actual value of a building
# and display the assessment value (60%) of the property and
# property tax (64cents for every 100$ of assessment value).

#perform the assessment calculation
def assessmentValue(properValue):
    assessPercent = .6
    return properValue*assessPercent

#perform the tax calculation
def propertyTax(assess):
    return (assess/100)*.64

#run the input statements
def main():
    actualValue = float(input('Please enter the numerical only value of your property: '))
    assessment = assessmentValue(actualValue)
    taxes = propertyTax(assessment)
    print('The assessment value of your property is $', assessment, '.')
    print('Your property taxes will be $', taxes, ' per year.')

#execute the above
main()
