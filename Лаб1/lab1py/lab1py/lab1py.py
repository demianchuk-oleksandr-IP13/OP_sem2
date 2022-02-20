from module1 import *

oldpath = "old.txt"
newpath = "new.txt"
createfile(oldpath)
createnew(oldpath, newpath)
print("your file: ")
outputfile(oldpath)
print("new file: ")
outputfile(newpath)
