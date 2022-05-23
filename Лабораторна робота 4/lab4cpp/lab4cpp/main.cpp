/*11. Спроектувати клас "Число", який представляє число і
містить методи збільшення / зменшення числа у вказану
кількість разів та знаходження модуля числа.
На основі цього класу створити класи-нащадки
"Раціональне число" та "Комплексне число".
Створити m об'єктів раціональних чисел та n об'єктів
комплексних чисел (дані згенерувати випадковим чином).
Раціональні числа зменшити у 2 рази, а комплексні —
збільшити у 3 рази. Знайти суму модулів усіх чисел.*/
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