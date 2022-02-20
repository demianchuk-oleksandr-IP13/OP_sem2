#include "func.h"

void createFile(string path) {
	ofstream outfile(path, ofstream::app);
	if (outfile) {
		cout << "ENTER to end line.\n CTRL+Z - end input file.\n";
		string line;
		getline(cin, line, '\26');
		outfile << line;
		outfile.close();
	}
	else {
		cout << "a file can't be opened";
	}
}


void outputFile(string path) {
	ifstream inFile;
	inFile.open(path);
	while (!inFile.eof()) {
		string textLine;
		getline(inFile, textLine);
		cout << textLine << endl;
	}
	inFile.close();
}

vector<string> split(string line, char sep = ' ') {
	vector<string> res;
	string slice = "";
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(slice);
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}

int wordAmt(string line) {
	vector<string> array = split(line);
	return array.size();
}

int maxLength(string line) {
	vector<string> array = split(line);
	int max = array[0].length();
	for (size_t i = 0; i < array.size(); i++){
		if (array[i].length() > max) {
			max = array[i].length();
		}
	}
	return max;
}

string transform(string line) {
	return "[" + to_string(wordAmt(line)) + "] " + line + " [" + to_string(maxLength(line)) + "]";
}

void createNew(string oldPath, string newPath) {
	ifstream oldFile;
	ofstream newFile;
	oldFile.open(oldPath);
	newFile.open(newPath);
	if (!oldFile.is_open() || !newFile.is_open()) {
		cout << "a file can't be opened" << endl;
	}
	else {
		while (!oldFile.eof()) {
			string temp = "";
			getline(oldFile, temp);
			if (temp.length() > 0) {
				temp = transform(temp);
				newFile << temp << "\n";
			}
		}
	}
	oldFile.close();
	newFile.close();
}
