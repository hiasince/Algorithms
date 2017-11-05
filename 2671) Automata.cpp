#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

vector<int> v[9];

int main() {
	v[0].push_back(2);
	v[0].push_back(1);
	v[1].push_back(3);
	v[1].push_back(-1);
	v[2].push_back(-1);
	v[2].push_back(4);
	v[3].push_back(5);
	v[3].push_back(-1);
	v[4].push_back(2);
	v[4].push_back(1);
	v[5].push_back(5);
	v[5].push_back(6);
	v[6].push_back(2);
	v[6].push_back(7);
	v[7].push_back(8);
	v[7].push_back(7);
	v[8].push_back(5);
	v[8].push_back(4);


	string input;

	cin >> input;
	int current = 0;

	for (int i = 0; i < input.size(); i++) {
		current = v[current][input[i] - '0'];
		if (current == -1)
			break;
	}

	if (current == 7 || current == 4 || current == 6)
		cout << "SUBMARINE" << endl;
	else
		cout << "NOISE" << endl;


	return 0;
}