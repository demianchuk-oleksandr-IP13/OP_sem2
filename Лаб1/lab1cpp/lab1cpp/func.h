#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void createFile(string);
void outputFile(string);
vector<string> split(string, char);
int wordAmt(string);
int maxLength(string);
string transform(string);
void createNew(string, string);