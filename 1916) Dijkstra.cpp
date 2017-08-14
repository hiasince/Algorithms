#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;

vector <pair<int, int>> bus[1001];
int cost[1001];

int main() {
	int N, M;
	int S, E;
	priority_queue<pair<int, int>> q;
	cin >> N >> M;

	for (int i = 0; i < 1001; i++) {
		cost[i] = -INT_MAX;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bool check = true;
		for (int j = 0; j < bus[a].size(); j++) {
			if (bus[a][j].first == b) {
				if (bus[a][j].second < -c)
					bus[a][j].second = -c;
				check = false;
			}
		}
		if (check)
			bus[a].push_back({ b,-c });
	}

	cin >> S >> E;
	//cost[S] = 0;
	q.push({ 0,S });

	while (!q.empty()) {
		pair<int, int> temp = q.top();
		q.pop();
		if (cost[temp.second] < temp.first) {
			cost[temp.second] = temp.first;
			for (int i = 0; i < bus[temp.second].size(); i++) {
				q.push({ bus[temp.second][i].second + temp.first,bus[temp.second][i].first });
			}
		}
	}

	cout << -cost[E] << endl;
}