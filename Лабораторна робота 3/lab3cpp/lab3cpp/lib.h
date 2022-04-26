#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class cPoint {
private:
    double ro = 1;
    int phi = 45;
    double z = 1;
public:
    cPoint(double Ro = 1, int Phi = 45, double Z = 1);
    cPoint(string line);
    cPoint(cPoint& pt);

    double GetRo();
    int GetPhi();
    double GetZ();

    double FindDistance();

    cPoint operator++ ();
    cPoint operator+= (double val);
    friend bool operator== (cPoint& a, cPoint& b);
};

vector<string> splitCoords(string);