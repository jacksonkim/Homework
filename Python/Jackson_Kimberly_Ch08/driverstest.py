# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 9?, Driver's Exam Grader, 10/29/13
# Description: Accept file input of a student's answers to the
# exam and count how many were correct. 

print("Driver's License exam Grader")
answerkey = ['B', 'D', 'A', 'A', 'C', 'A', 'B',
             'A', 'C', 'D', 'B', 'C', 'D', 'A',
             'D', 'C', 'C', 'B', 'D', 'A']
studentanswers = []
for steps in range(20):
    student = str(input("Please enter in the next answer for number: "))
    studentanswers.append(student)
correct = 0
for steps in range(20):
    if (answerkey[steps] == studentanswers[steps]):
        correct += 1

if (correct >= 15):
    print("Good job passing. Number of questions correct:", correct)
else:
    print("Sorry, thats a failure.")
