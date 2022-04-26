#include "lib.h"

int inputSize() {
	int size = 0;
	do {
		std::cout << "Введiть кiлькiсть точок: ";
		std::cin >> size;
		std::cout << std::endl;
	} while (size <= 0);
	return size;
}

Point::Point() {
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}
Point::Point(double x, double y, double z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}
double Point::getX() {
	return X;
}
double Point::getY() {
	return Y;
}
double Point::getZ() {
	return Z;
}

Point* createArray(int size) {
	Point* Array = new Point[size];
	for (size_t i = 0; i < size; i++) {
		double x, y, z = 0;
		std::cout << i + 1 << ") Введiть координати: ";
		std::cout << "\tx: "; std::cin >> x;
		std::cout << "\t\t\ty: "; std::cin >> y;
		std::cout << "\t\t\tz: "; std::cin >> z;
		std::cout << std::endl;
		Point Pt(x, y, z);
		Array[i] = Pt;
	}
	return Array;
}

void displayArray(Point* Array, int size) {
	for (size_t i = 0; i < size; i++)
		std::cout << "Точка " << i + 1 << ": (" << Array[i].getX() << ", " << Array[i].getY() << ", " << Array[i].getZ() << ")\n";
	std::cout << std::endl;
}

int numberOfAskedPoints(Point* Array, int size) {
	int n = 0;
	for (size_t i = 0; i < size; i++) {
		if (Array[i].getX() == int(Array[i].getX()) && Array[i].getY() == int(Array[i].getY()) && Array[i].getZ() == int(Array[i].getZ()) && Array[i].getX() > 0 && Array[i].getY() > 0 && Array[i].getZ() > 0)
			n++;
	}
	return n;
}