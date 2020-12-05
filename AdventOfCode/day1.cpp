using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<int> getItemsWithindexList(vector<int> input, vector<int> indexes) {
	vector<int> output;
	for (int i = 0; i < indexes.size(); i++) {
		output.push_back(input.at(indexes.at(i)));
	}
	return output;
}

bool itemsAddUpTo(vector<int> items, int addUpTo) {
	int sum = 0;
	for (int i = 0; i < items.size(); i++) sum += items.at(i);
	return sum == addUpTo;
}

vector<int> itemsInVectorThatAddUpTo(vector<int> input, int amount, int addUpTo, vector<int> currentItemIndexes = vector<int>()) {
	if (currentItemIndexes.size() == amount) {
		vector<int> items = getItemsWithindexList(input, currentItemIndexes);
		if (itemsAddUpTo(items, addUpTo)) return items;
	}
	else {
		for (int i = 0; i < input.size(); i++) {
			if (find(currentItemIndexes.begin(), currentItemIndexes.end(), i) != currentItemIndexes.end()) continue;
			vector<int> newIndexes = currentItemIndexes;
			newIndexes.push_back(i);
			vector<int> nextOutput = itemsInVectorThatAddUpTo(input, amount, addUpTo, newIndexes);
			if (nextOutput.size() != 0) return nextOutput;
		}
	}
}

void day1Task1() {
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

void day1Task2() {
	vector<int> input;
	ifstream in("../Debug/input.txt");
	string str;
	while (getline(in, str)) {
		if (str.size() > 0) {
			input.push_back(stoi(str));
		}
	}
	in.close();

	vector<int> items = itemsInVectorThatAddUpTo(input, 3, 2020);
	cout << items.at(0) * items.at(1) * items.at(2);
}