#include "lib.h"

void fileInput(string path) {
	ofstream file(path, ios::binary);
	
	product tovar;
	int amount;

	cout << "wwedit' kilkist' produktiv: "; cin >> amount; cout << endl;
	for (size_t i = 0; i < amount; i++) {
		cout << i+1 << ") " << "nazwa tovaru: "; cin >> tovar.name;

		cout << "data wypusku tovaru: ";
		string day; getline(cin, day, '.'); tovar.releaseDay = stoi(day);
		string month; getline(cin, month, '.'); tovar.releaseMonth = stoi(month);
		string year; getline(cin, year, '\n'); tovar.releaseYear = stoi(year);

		cout << "termin prydatnosti tovaru: ";
		getline(cin, day, '.'); tovar.expireDay = stoi(day);
		getline(cin, month, '.'); tovar.expireMonth = stoi(month);
		getline(cin, year, '\n'); tovar.expireYear = stoi(year);

		cout << "cina tovaru: "; cin >> tovar.price; cout << endl;
		
		int days[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		int totalReleaseDays = tovar.releaseDay + days[tovar.releaseDay - 1];
		int totalExpireDays = tovar.expireDay + days[tovar.releaseDay - 1];
		int diff = totalExpireDays - totalReleaseDays;
		
		if (diff <= 14 && tovar.releaseYear == tovar.expireYear) {
			tovar.price *= 0.95;
			tovar.price = round(tovar.price * 100) / 100;
		}
		else if (diff > 0 && tovar.releaseYear < tovar.expireYear) {
			tovar.price *= 1.03;
			tovar.price = round(tovar.price * 100) / 100;
		}
		file.write((char*)&tovar, sizeof(product));

	}
	file.close();
}

void fileOutput(string path) {
	product tovar;
	ifstream file(path, ios::binary);

	cout << endl << "[ " << path << " ]" << endl;

	while (file.read((char*)&tovar, sizeof(product))) {
		cout << "\nnazwa: " << tovar.name << endl;
		cout << "data wypusku:" << tovar.releaseDay << "." << tovar.releaseMonth << "." << tovar.releaseYear << endl;
		cout << "termin prydatnosti: " << tovar.expireDay << "." << tovar.expireMonth << "." << tovar.expireYear << endl;
		cout << "wartist': " << tovar.price << " hrn" << endl;
	}
	
	file.close();
}


void copyFile(string path, string newpath) {
	product tovar;
	ifstream file(path, ios::binary);
	ofstream newfile(newpath, ios::binary);

	time_t t = time(0);
	tm* now = localtime(&t);
	const int yearnow = now->tm_year + 1900;
	const int monthnow = now->tm_mon + 1;

	while (file.read((char*)&tovar, sizeof(product))) {
		if (tovar.releaseMonth < monthnow && tovar.releaseYear <= yearnow) {
			newfile.write((char*)&tovar, sizeof(product));
		}
	}
	file.close();
	newfile.close();
}
