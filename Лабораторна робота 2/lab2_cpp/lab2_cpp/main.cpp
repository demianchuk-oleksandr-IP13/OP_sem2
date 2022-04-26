/*11. Розробити клас "точка в просторi”, який заданий своїми
координатами. Створити масив об'єктiв даного класу. Визначити
кiлькiсть точок з цiлочисельними координатами, якi попадають
в перший октант.*/

#include "lib.h"

int main() {
	setlocale(LC_CTYPE, "rus");
	int s = inputSize();
	Point* Arr = createArray(s);
	displayArray(Arr, s);
	std::cout << "Кiлькiсть точок з цiлочисельними координатами, якi попадають в перший октант: " << numberOfAskedPoints(Arr, s);
	delete[] Arr;
}