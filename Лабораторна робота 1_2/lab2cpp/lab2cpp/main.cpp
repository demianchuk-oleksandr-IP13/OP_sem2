/*11. �������� ���� i� ������� ������ � ��������: 
������������, ���� �������, ������� ����� ����������, 
����. ������� ���� �� 5% �� �� ������, ������������ 
����� ��������� ���� �� �������� ���� ������. 
ϳ������� ���� �� 3% �� ������, ������������ ����� 
��������� ���� ���� ������ ����. ������������ 
����� ��������� ����������� �� ������ �������� 
������ ���������� �� ���� ������� ������. 
��������� � ����� ���� ���� ��� ������, ��������� 
������ ��������� �����.*/
#include "lib.h"
int main() {
	string file, newfile;
	cout << "enter the filename: "; cin >> file; cout << endl;
	fileInput(file);
	fileOutput(file);
	cout << "enter the name for a new file: "; cin >> newfile; cout << endl;
	copyFile(file, newfile);
	fileOutput(newfile);
	return 0;
}