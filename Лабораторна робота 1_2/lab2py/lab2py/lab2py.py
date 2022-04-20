from module1 import *

oldpath = "old.txt"
newpath = "new.txt"
createfile(oldpath)
print("your file: ")
outputfile(oldpath)
copyfile(oldpath, newpath)
print("new file: ")
outputfile(newpath)