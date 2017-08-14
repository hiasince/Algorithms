#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<int, int>> e[10001];

int main() {

	int spanning[10001];
	int N, M;
	long long sum = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({ b,c });
		e[b].push_back({ a,c });
	}

	for (int i = 0; i < 10001; i++) {
		spanning[i] = 1000002;
	}

	spanning[1] = -1000003;
	for (int i = 0; i < e[1].size(); i++) {
		spanning[e[1][i].first] = e[1][i].second;
	}

	for (int i = 1; i < N; i++) {
		int min_value = INT_MAX;
		int min_index = -1;

		for (int j = 1; j <= N; j++) {
			if (spanning[j] > -1000003 && min_value > spanning[j]) {
				min_value = spanning[j];
				min_index = j;
			}
		}

		sum += min_value;
		spanning[min_index] = -1000003;

		for (int j = 0; j < e[min_index].size(); j++) {
			if (spanning[e[min_index][j].first] > e[min_index][j].second)
				spanning[e[min_index][j].first] = e[min_index][j].second;
		}
	}

	cout << sum << endl;

	return 0;
}



