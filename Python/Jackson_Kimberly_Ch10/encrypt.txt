# CIST 2742 - 20389 - Kimberly Jackson SID: 0332
# Chapter 10, Encrypted file - 11/14/13
# Description: Accept a file's input and convert it
# based on a code key so that it will encrypt it.

codes = { 'A':'9', 'B':'6', 'C':'7', 'D':'2', 'E':'1', 'F':'3', 'G':'5',
          'H':'0', 'I':'4', 'J':'8', 'K':'p', 'L':'q', 'M':'z', 'N':'e',
          'O':'h', 'P':'u', 'Q':'k', 'R':'a', 'S':'v', 'T':'y', 'U':'l',
          'V':'I', 'W':'A', 'X':'T', 'Y':'M', 'Z':'i',
          
          'a':'(', 'b':'&', 'c':'J', 'd':'t', 'e':'V', 'f':'H', 'g':'P',
          'h':'$', 'i':'E', 'j':'s', 'k':'B', 'l':'c', 'm':'f', 'n':'O',
          'o':'#', 'p':'R', 'q':'F', 'r':'K', 's':'i', 't':'Z', 'u':'x',
          'v':'r', 'w':'z', 'x':'w', 'y':'X', 'z':'C',
          
          '0':'@', '1':'%', '2':'*', '3':')', '4':'j', '5':'Y', '6':'L',
          '7':'Q', '8':'V', '9':'b', ' ':' ', '\'':'\'', '\n':'\n', ',':','}

infile = open('stories.txt', 'r')
outfile = open('legends.txt', 'w')
line = infile.readline()
linechange = ""

while (line != ''):
    #print(line)
    for ch in line:
        linechange += codes.get(ch, '.')
            
    #print(linechange)
    line = infile.readline()

outfile.write(linechange)
print("File has been encrypted.")
#don't forget to close the file or it won't push the contents
#to the legends file. :I
outfile.close()
infile.close()
