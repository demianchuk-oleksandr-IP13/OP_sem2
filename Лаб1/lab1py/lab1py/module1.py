def createfile(file):
    print("ENTER to end line.\n >< - end input file.\n")
    lines = []
    while True:
        line = input()
        if line.find("><") != -1:
            lines.append(line[0:-2])
            break
        else:
            lines.append(line)
    file = open(file, "a")
    file.write('\n'.join(lines))
    file.close()

def outputfile(path):
    file = open(path, 'r')
    for line in file:
        print(line)
    file.close()

def wordamt(line):
    return len(line.split())

def maxlength(line):
    words = line.split()
    max = len(words[0])
    for i in range(len(words)):
        if max < len(words[i]):
            max = len(words[i])
    return max

def transform(line):
    if len(line) > 0:
        return "[" + str(wordamt(line)) + "] " + line + "[" + str(maxlength(line)) + "]\n"
    else:
        return ""

def createnew(oldpath, newpath):
    old = open(oldpath, 'r')
    new = open(newpath, 'w')
    for line in old:
        line = line.rstrip(line[-1])
        line = transform(line)
        new.write(line)
    old.close()
    new.close()