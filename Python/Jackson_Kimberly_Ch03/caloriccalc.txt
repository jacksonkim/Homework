# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 3, Caloric Calc - 9/5/13
# Description: Ask a user for the carb and fat gram intake in a day.
# Calculate calories from carbs = carbs*4
# Calculate calories from fat = fat*9

#calories from fat
def fatCals(fatg):
    return fatg*9

#calories from carbohydrates
def carbCals(carbg):
    return carbg*4

#main IO function
def main():
    fatgrams = float(input('Please enter in the numerical only value of grams of FAT consumed in a day: '))
    carbgrams = float(input('Please enter in the numerical only value of grams of CARBOHYDRATES consumed in a day: '))
    print('Calories from fat is about', fatCals(fatgrams), '\nCalories from carbs is about', carbCals(carbgrams))

#execute the stupid thing
main()
