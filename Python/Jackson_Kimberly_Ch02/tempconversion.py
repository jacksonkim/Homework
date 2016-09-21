# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Week 2, Exercise 9 - F to C Converter - 8/29/13
# Description: Convert fahrenheit to celsius and celsius to fahrenheit
# utilizing the formula F = 9/5C + 32.
# Or more accurately: F = (9/5*C)+32
# Reverse it and you get C = (F-32)*5/9
fahrenheit = float(input('Please enter in the temperature in fahrenheit: '))
conversion = (fahrenheit-32)*5/9
print(fahrenheit, 'degrees fahrenheit is', format(conversion, '3.1f'), 'degrees celsius.')
celsius = float(input('Please enter in the temperature in celsius: '))
conversion = (9/5*celsius)+32
print(celsius, 'degrees celsius is', format(conversion, '3.1f'), 'degrees fahrenheit.')
