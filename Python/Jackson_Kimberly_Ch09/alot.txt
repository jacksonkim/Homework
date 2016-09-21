# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 9, You sure use that a lot, 11/5/13
# Description: Accept input from a user and then count the
# characters to determine which is used most frequently.


engli = input("Enter in the word(s) you would like to check: ")
engli = engli.upper()
used = [0] * 40
for ch in engli:
    if (ch == ' '):
        used[0] += 1
    elif (ch == ','):
        used[1] += 1
    elif (ch == '.'):
        used[2] += 1
    elif (ch == '?'):
        used[3] += 1
    elif (ch == '0'):
        used[4] += 1
    elif (ch == '1'):
        used[5] += 1
    elif (ch == '2'):
        used[6] += 1
    elif (ch == '3'):
        used[7] += 1
    elif (ch == '4'):
        used[8] += 1
    elif (ch == '5'):
        used[9] += 1
    elif (ch == '6'):
        used[10] += 1
    elif (ch == '7'):
        used[11] += 1
    elif (ch == '8'):
        used[12] += 1
    elif (ch == '9'):
        used[13] += 1
    elif (ch == 'A'):
        used[14] += 1
    elif (ch == 'B'):
        used[15] += 1
    elif (ch == 'C'):
        used[16] += 1
    elif (ch == 'D'):
        used[17] += 1
    elif (ch == 'E'):
        used[18] += 1
    elif (ch == 'F'):
        used[19] += 1
    elif (ch == 'G'):
        used[20] += 1
    elif (ch == 'H'):
        used[21] += 1
    elif (ch == 'I'):
        used[22] += 1
    elif (ch == 'J'):
        used[23] += 1
    elif (ch == 'K'):
        used[24] += 1
    elif (ch == 'L'):
        used[25] += 1
    elif (ch == 'M'):
        used[26] += 1
    elif (ch == 'N'):
        used[27] += 1
    elif (ch == 'O'):
        used[28] += 1
    elif (ch == 'P'):
        used[29] += 1
    elif (ch == 'Q'):
        used[30] += 1
    elif (ch == 'R'):
        used[31] += 1
    elif (ch == 'S'):
        used[32] += 1
    elif (ch == 'T'):
        used[33] += 1
    elif (ch == 'U'):
        used[34] += 1
    elif (ch == 'V'):
        used[35] += 1
    elif (ch == 'W'):
        used[36] += 1
    elif (ch == 'X'):
        used[37] += 1
    elif (ch == 'Y'):
        used[38] += 1
    elif (ch == 'Z'):
        used[39] += 1

freq = max(used)
freqindex = used.index(freq)

print("The most frequently used character is:", end=' ')
if (freqindex == 0 ):
	print(' ')
elif (freqindex == 1):
	print(',')
elif (freqindex == 2):
	print('.')
elif (freqindex == 3):
	print('?')
elif (freqindex == 4):
	print(0)
elif (freqindex == 5):
	print(1)
elif (freqindex == 6):
	print(2)
elif (freqindex == 7):
	print(3)
elif (freqindex == 8):
	print(4)
elif (freqindex == 9):
	print(5)
elif (freqindex == 10):
	print(6)
elif (freqindex == 11):
	print(7)
elif (freqindex == 12):
	print(8)
elif (freqindex == 13):
	print(9)
elif (freqindex == 14):
	print('A')
elif (freqindex == 15):
	print('B')
elif (freqindex == 16):
	print('C')
elif (freqindex == 17):
	print('D')
elif (freqindex == 18):
	print('E')
elif (freqindex == 19):
	print('F')
elif (freqindex == 20):
	print('G')
elif (freqindex == 21):
	print('H')
elif (freqindex == 22):
	print('I')
elif (freqindex == 23):
	print('J')
elif (freqindex == 24):
	print('K')
elif (freqindex == 25):
	print('L')
elif (freqindex == 26):
	print('M')
elif (freqindex == 27):
	print('N')
elif (freqindex == 28):
	print('O')
elif (freqindex == 29):
	print('P')
elif (freqindex == 30):
	print('Q')
elif (freqindex == 31):
	print('R')
elif (freqindex == 32):
	print('S')
elif (freqindex == 33):
	print('T')
elif (freqindex == 34):
	print('U')
elif (freqindex == 35):
	print('V')
elif (freqindex == 36):
	print('W')
elif (freqindex == 37):
	print('X')
elif (freqindex == 38):
	print('Y')
elif (freqindex == 39):
	print('Z')

print("with", freq, "uses.")
