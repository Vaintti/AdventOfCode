using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void day1_task1() {
	vector<int> input;
	ifstream in("../Debug/input.txt");
	string str;
	while (getline(in, str)) {
		if (str.size() > 0) {
			input.push_back(stoi(str));
		}
	}
	in.close();

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (i == j) continue;
			int value1 = input.at(i);
			int value2 = input.at(j);
			if (value1 + value2 == 2020) {
				cout << value1 * value2;
				return;
			}
		}
	}
}