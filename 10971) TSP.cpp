#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <climits>
#include <list>
using namespace std;

int N;
int map[10][10];
int ST[10][1024];

void dfs(int current, int state, int cost) {

	if (state == (1 << N) - 1)
		return;

	for (int i = 0; i < N; i++) {
		if ((state & (1 << i)) != (1 << i)) {
			if (map[current][i] > 0) {
				if (ST[i][state | (1 << i)] > cost + map[current][i]) {
					ST[i][state | (1 << i)] = cost + map[current][i];
					dfs(i, state | (1 << i), cost + map[current][i]);
				}
			}
		}
	}
}

int main() {

	cin >> N;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 1024; i++) {
			ST[j][i] = INT_MAX;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0, 0);

	cout << ST[0][(1 << N) - 1] << endl;

	return 0;
}

