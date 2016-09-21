# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 6, Average Generator - 10/3/13
# Description: calc_average accepts 5 test scores to generate an average.
# determine_grade accepts one test score and displays the letter grade.
# Display a letter grade for all five test scores, calculates the average
# and displays the grade for that as well.

#accept five scores
def calc_average(grade1, grade2, grade3, grade4, grade5):
    return (grade1+grade2+grade3+grade4+grade5)/5

#letter grades
def determine_grade(score):
    if (score >=90):
        return 'A'
    elif (score >=80):
        return 'B'
    elif (score >=70):
        return 'C'
    elif (score >=60):
        return 'D'
    elif (score <60):
        return 'F'

#do the rest of it
def main():
    #get the inputs
    test1=float(input("Please enter in the numerical value of the first test score: "))
    test2=float(input("And now for test 2: "))
    test3=float(input("And now for test 3: "))
    test4=float(input("And now for test 4: "))
    test5=float(input("Finally, the last test: "))

    #determine the letter grades
    print("\nLetter grade for test 1:", determine_grade(test1))
    print("Letter grade for test 2:", determine_grade(test2))
    print("Letter grade for test 3:", determine_grade(test3))
    print("Letter grade for test 4:", determine_grade(test4))
    print("Letter grade for test 5:", determine_grade(test5))

    #and for the average
    average = calc_average(test1, test2, test3, test4, test5)
    print("\nAverage grade for all 5 tests:", format(average, '.1f'))
    print("Average letter grade for all tests:", determine_grade(average))

#execute everything
main()


    
