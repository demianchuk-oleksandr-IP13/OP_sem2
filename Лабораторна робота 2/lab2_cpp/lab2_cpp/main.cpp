/*11. ��������� ���� "����� � �������i�, ���� ������� �����
������������. �������� ����� ��'���i� ������ �����. ���������
�i���i��� ����� � �i������������ ������������, ��i ���������
� ������ ������.*/

#include "lib.h"

int main() {
	setlocale(LC_CTYPE, "rus");
	int s = inputSize();
	Point* Arr = createArray(s);
	displayArray(Arr, s);
	std::cout << "�i���i��� ����� � �i������������ ������������, ��i ��������� � ������ ������: " << numberOfAskedPoints(Arr, s);
	delete[] Arr;
}