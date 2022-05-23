#pragma once
#include <iostream>
#include <cmath>
#include <vector>

class Number {
public:
    Number();
    virtual void multiply(double times) = 0;
    virtual void divide(double times) = 0;
    virtual double getReal() = 0;
    virtual double findAbs() = 0;
};

class Rational : public Number {
private:
    double real;
public:
    Rational();
    Rational(double Re);
    void multiply(double times);
    void divide(double times);
    double getReal();
    double findAbs();
};

class Complex : public Number {
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double Re, double Im);
    void multiply(double times);
    void divide(double times);
    double getReal();
    double getImag();
    double findAbs();
};

int input();

Rational* RatArray(int size);
Complex* CompArray(int size);

void displayRat(Rational* Array, int size);
void displayComp(Complex* Array, int size);

void changeRat(Rational* Array, int size);
void changeComp(Complex* Array, int size);

double findSum(Rational* Arr1, int m, Complex* Arr2, int n);