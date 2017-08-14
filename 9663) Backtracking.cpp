#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v_Queen;
int map[15][15];
pair<int, int> temp;
int N;
int COUNT = 0;

bool is_Promise(int x, int y) {
	for (int i = 0; i < v_Queen.size(); i++) {
		if (v_Queen[i].first == x || v_Queen[i].second == y)
			return false;
		else if (abs(v_Queen[i].first - x) == abs(v_Queen[i].second - y))
			return false;
	}
	return true;
}

void backtracking(int curX, int curY) {
	temp = v_Queen.back();
	for (int a = 0; a < N; a++) {
		if (is_Promise(temp.first + 1, a)) {
			if (temp.first + 1 == N - 1) {
				COUNT++;
			}
			else {
				v_Queen.push_back({ temp.first + 1, a });
				backtracking(temp.first + 1, a);
				temp = v_Queen.back();
			}
		}
	}
	v_Queen.pop_back();
}

int main() {

	memset(map, -1, sizeof(int) * 225);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		v_Queen.push_back({ 0,i });
		backtracking(0, i);
	}
	if (N == 1)
		COUNT = 1;
	cout << COUNT << endl;

	return 0;

}