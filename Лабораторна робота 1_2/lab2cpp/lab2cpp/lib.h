#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct product {
	char name[30];
	int releaseDay;
	int releaseMonth;
	int releaseYear;
	int expireDay;
	int expireMonth;
	int expireYear;
	double price;
};
void chooseinput(string);
void fileInput(string);
void fileOutput(string);
void changePrices(string);
void copyFile(string, string);
