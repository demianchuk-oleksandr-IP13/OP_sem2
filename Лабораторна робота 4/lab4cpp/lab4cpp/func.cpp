#include "func.h"

Number::Number() {}

Rational::Rational() {}

Rational::Rational(double Re) {
	real = Re;
}

void Rational::multiply(double times) {
	real *= times;
}

void Rational::divide(double times) {
	real /= times;
}

double Rational::getReal() {
	return real;
}

double Rational::findAbs() {
	return sqrt(real * real);
}


Complex::Complex() {}

Complex::Complex(double Re, double Im) {
	real = Re;
	imaginary = Im;
}

void Complex::multiply(double times) {
	real *= times;
	imaginary *= times;
}

void Complex::divide(double times) {
	real /= times;
	imaginary /= times;
}

double Complex::getReal() {
	return real;
}

double Complex::getImag() {
	return imaginary;
}

double Complex::findAbs() {
	return sqrt(real * real + imaginary * imaginary);
}

int input() {	
	int num = 0;
	do {
		std::cout << "enter the size: "; std::cin >> num;
	} while (num <= 0);
	return num;
}

Rational* RatArray(int size) {
	Rational* Array = new Rational[size];
	double min = -100.0;
	double max = 100.0;
	for (size_t i = 0; i < size; i++) {
		double Re = (double)(rand()) / RAND_MAX * (max - min) + min;
		Rational R(Re);
		Array[i] = R;
	}
	return Array;
}

Complex* CompArray(int size) {
	Complex* Array = new Complex[size];
	double min = -100.0;
	double max = 100.0;
	for (int i = 0; i < size; i++) {
		double Re = (double)(rand()) / RAND_MAX * (max - min) + min;
		double Im = (double)(rand()) / RAND_MAX * (max - min) + min;
		Complex C(Re, Im);
		Array[i] = C;
	}
	return Array;
}

void displayRat(Rational* Array, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d) %3.3f \n", i + 1, Array[i].getReal());
	}
	std::cout << std::endl;
}

void displayComp(Complex* Array, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d) %3.3f + %3.3f*i \n", i + 1, Array[i].getReal(), Array[i].getImag());
	}
	std::cout << std::endl;
}

void changeRat(Rational* Array, int size) {
	for (size_t i = 0; i < size; i++)
	{
		Array[i].divide(2);
	}
}

void changeComp(Complex* Array, int size) {
	for (size_t i = 0; i < size; i++)
	{
		Array[i].multiply(3);
	}
}

double findSum(Rational* Arr1, int m, Complex* Arr2, int n) {
	double sum = 0;
	for (size_t i = 0; i < m; i++)
	{
		sum += Arr1[i].findAbs();
	}
	for (size_t i = 0; i < n; i++)
	{
		sum += Arr2[i].findAbs();
	}
	return sum;
}