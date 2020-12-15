using namespace std;

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

vector<vector<char>> getPattern() {
	ifstream in("../Debug/input_d3_t1.txt");
	string str;
	vector<vector<char>> pattern;

	while (getline(in, str)) {
		vector<char> line;
		for (char c : str) {
			line.push_back(c);
		}
		pattern.push_back(line);
	}

	return pattern;
}

int treesInPath(int stepWidth, int stepHeight, vector<vector<char>> pattern) {
	int trees = 0;

	for (int i = 1; i * stepHeight < pattern.size(); i++) {
		vector<char> linePattern = pattern.at(i * stepHeight);
		int currentWidth = stepWidth * i;
		int patternCount = currentWidth / linePattern.size() + 1;
		vector<char> line;
		for (int i = 0; i < patternCount; i++) {
			line.insert(line.end(), linePattern.begin(), linePattern.end());
		}
		if (line.at(currentWidth) == '#') trees++;
	}

	return trees;
}

void day3Task1() {
	vector<vector<char>> pattern = getPattern();
	int trees = treesInPath(3, 1, pattern);

	cout << "There are " << trees << " trees in the path.";
}

void day3Task2() {
	vector<vector<char>> pattern = getPattern();
	
	int multiplied = treesInPath(1, 1, pattern);
	multiplied *= treesInPath(3, 1, pattern);
	multiplied *= treesInPath(5, 1, pattern);
	multiplied *= treesInPath(7, 1, pattern);
	multiplied *= treesInPath(1, 2, pattern);


	cout << "All paths multiplied: " << multiplied;
}