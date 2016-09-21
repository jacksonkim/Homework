# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 9, Morse Code Conversion, 11/5/13
# Description: Accept input from a user as a string and then
# convert it into Morse code using a chart from the book.
# It's too big, look in the book, geez.

engli = input("Enter in the word\(s\) you would like to convert: ")
print(engli, "in Morse code is:")
engli = engli.upper()
for ch in engli:
    if (ch == ' '):
        print(' ')
    elif (ch == ','):
        print('--..--')
    elif (ch == '.'):
        print('.-.-.-')
    elif (ch == '?'):
        print('..--..')
    elif (ch == '0'):
        print('-----')
    elif (ch == '1'):
        print('.----')
    elif (ch == '2'):
        print('..---')
    elif (ch == '3'):
        print('...--')
    elif (ch == '4'):
        print('....-')
    elif (ch == '5'):
        print('.....')
    elif (ch == '6'):
        print('-....')
    elif (ch == '7'):
        print('--...')
    elif (ch == '8'):
        print('---..')
    elif (ch == '9'):
        print('----.')
    elif (ch == 'A'):
        print('.-')
    elif (ch == 'B'):
        print('-...')
    elif (ch == 'C'):
        print('-.-.')
    elif (ch == 'D'):
        print('-..')
    elif (ch == 'E'):
        print('.')
    elif (ch == 'F'):
        print('..-.')
    elif (ch == 'G'):
        print('--.')
    elif (ch == 'H'):
        print('....')
    elif (ch == 'I'):
        print('..')
    elif (ch == 'J'):
        print('.---')
    elif (ch == 'K'):
        print('-.-')
    elif (ch == 'L'):
        print('.-..')
    elif (ch == 'M'):
        print('--')
    elif (ch == 'N'):
        print('-.')
    elif (ch == 'O'):
        print('---')
    elif (ch == 'P'):
        print('.--.')
    elif (ch == 'Q'):
        print('--.-')
    elif (ch == 'R'):
        print('.-.')
    elif (ch == 'S'):
        print('...')
    elif (ch == 'T'):
        print('-')
    elif (ch == 'U'):
        print('..-')
    elif (ch == 'V'):
        print('...-')
    elif (ch == 'W'):
        print('.--')
    elif (ch == 'X'):
        print('-..-')
    elif (ch == 'Y'):
        print('-.-')
    elif (ch == 'Z'):
        print('--..')
