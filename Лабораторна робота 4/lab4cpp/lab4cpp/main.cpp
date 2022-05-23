/*11. ������������ ���� "�����", ���� ����������� ����� �
������ ������ ��������� / ��������� ����� � �������
������� ���� �� ����������� ������ �����.
�� ����� ����� ����� �������� �����-�������
"����������� �����" �� "���������� �����".
�������� m ��'���� ������������ ����� �� n ��'����
����������� ����� (��� ����������� ���������� �����).
���������� ����� �������� � 2 ����, � ��������� �
�������� � 3 ����. ������ ���� ������ ��� �����.*/
#include "func.h"

int main() {
	int m = input();
	int n = input();
	Rational* arrR = RatArray(m);
	Complex* arrC = CompArray(n);
	std::cout << m << " rational numbers: \n";
	displayRat(arrR, m);
	std::cout << n << " complex numbers: \n";
	displayComp(arrC, n);
	std::cout << "rational divided by 2: \n";
	changeRat(arrR, m);
	displayRat(arrR, m);
	std::cout << "complex multiplied by 3: \n";
	changeComp(arrC, n);
	displayComp(arrC, n);
	std::cout << "the sum of abs equals " << findSum(arrR, m, arrC, n);
	delete[] arrR;
	delete[] arrC;
}