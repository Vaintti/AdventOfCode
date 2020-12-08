using namespace std;

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void day2Task1() {
	int validCount = 0;
	ifstream in("../Debug/input_d2_t1.txt");
	string str;
	while (getline(in, str)) {
		if (str.size() <= 0) continue;
		int splitIndex = str.find(": ");
		string rule = str.substr(0, splitIndex);
		string password = str.substr(splitIndex + 2, str.length() - (splitIndex + 2));

		splitIndex = rule.find(" ");
		string range = rule.substr(0, splitIndex);
		char letter = rule.at(splitIndex + 1);

		splitIndex = range.find("-");
		int min = stoi(range.substr(0, splitIndex));
		int max = stoi(range.substr(splitIndex + 1, range.length() - (splitIndex + 1)));

		int lettersInPassword = 0;

		for (char& c : password) {
			if (c == letter) lettersInPassword++;
		}

		if (lettersInPassword < min || lettersInPassword > max) continue;

		validCount++;
	}
	in.close();

	cout << validCount;
}

void day2Task2() {
	int validCount = 0;
	ifstream in("../Debug/input_d2_t1.txt");
	string str;
	while (getline(in, str)) {
		if (str.size() <= 0) continue;
		int splitIndex = str.find(": ");
		string rule = str.substr(0, splitIndex);
		string password = str.substr(splitIndex + 2, str.length() - (splitIndex + 2));

		splitIndex = rule.find(" ");
		string range = rule.substr(0, splitIndex);
		char letter = rule.at(splitIndex + 1);

		splitIndex = range.find("-");
		int first = stoi(range.substr(0, splitIndex)) - 1;
		int second = stoi(range.substr(splitIndex + 1, range.length() - (splitIndex + 1))) -1;

		bool onlyFirstIsLetter = password.at(first) == letter && password.at(second) != letter;
		bool onlySecondIsLetter = password.at(first) != letter && password.at(second) == letter;
		if (onlyFirstIsLetter || onlySecondIsLetter) validCount++;
	}
	in.close();

	cout << validCount;
}