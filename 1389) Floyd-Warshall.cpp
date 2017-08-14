#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int rel[101][101];
	queue<pair<int, int>> q;
	int M, N, sum, ans;
	int min = INT_MAX;
	cin >> M >> N;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j <101; j++) {
			rel[i][j] = 200000;
		}
	}
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= M; k++) {
				if (rel[k][j] > rel[k][i] + rel[i][j]) {
					rel[k][j] = rel[k][i] + rel[i][j];
				}
			}
		}
	}


	for (int i = 1; i <= M; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			if (j != i)
				sum += rel[i][j];
		}
		if (sum < min) {
			min = sum;
			ans = i;
		}
	}

	cout << ans << endl;

	return 0;

}