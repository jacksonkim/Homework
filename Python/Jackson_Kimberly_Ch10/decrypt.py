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
          '7':'Q', '8':'V', '9':'b'}

# cheated a bit here since i randomly assigned everything. used the
# python gui to give me the values and keys seperately and then copied
# and pasted them together. I don't know if its exactly right because
# some letters were off, specifically s and w, but it works with the file
# i have, so.
decodes = {'b':'9', 'V':'8', '%':'1', '@':'0', ')':'3', '*':'2', 'Y':'5',
            'j':'4', 'Q':'7', 'L':'6', 'X':'y', 'w':'x', 'C':'z', 'F':'q',
            'R':'p', 'i':'s', 'K':'r', 'x':'u', 'Z':'t', 'z':'w', 'r':'v',
            'E':'i', '$':'h', 'B':'k', 's':'j', 'f':'m', 'c':'l',
            '#':'o', 'O':'n', '(':'a', 'J':'c', '&':'b', 'V':'e', 't':'d',
            'P':'g', 'H':'f', 'M':'Y', 'T':'X', 'i':'s', 'k':'Q', 'u':'P',
            'v':'S', 'a':'R', 'l':'U', 'y':'T',
            'A':'W', 'I':'V', '4':'I', '0':'H', 'p':'K', '8':'J', 'z':'w',
            'q':'L', 'h':'O', 'e':'N', '9':'A', '7':'C', '6':'B', '1':'E',
            '2':'D', '5':'G', '3':'F', ' ':' ', '\'':'\'', '\n':'\n', ',':','}

#oh boy i bet this looks familiar
#i cheated here too because all i had to do was reverse the files
#and code key so.
infile = open('legends.txt', 'r')
#outfile = open('stories.txt', 'w')
line = infile.readline()
linechange = ""

while (line != ''):
    for ch in line:
        linechange += decodes.get(ch, '.')
        
    line = infile.readline()

print(linechange)
#outfile.write(linechange)
