#include "func.h"

int main()
{
    setlocale(LC_ALL, ".1251");
    string oldPath = "old.txt";
    string newPath = "new.txt";
    createFile(oldPath);
    createNew(oldPath, newPath);
    cout << "your file : \n";
    outputFile(oldPath);
    cout << "new file : \n";
    outputFile(newPath);
}