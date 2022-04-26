#pragma once
#include <iostream>

class Point {
private:
	double X;
	double Y;
	double Z;
public:
	Point();
	Point(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
};

int inputSize();
Point* createArray(int size);
void displayArray(Point* Array, int size);
int numberOfAskedPoints(Point* Array, int size);
