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

int map[1001][1001];
bool visit[1001];
int N, M, V;

void dfs(int cur) {
	for (int i = 1; i <= N; i++) {
		if (map[cur][i] == 1 && visit[i] != true) {
			cout << i << " ";
			visit[i] = 1;
			dfs(i);
		}
	}
}

int main() {


	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	visit[V] = 1;
	cout << V << " ";
	dfs(V);

	cout << endl;
	for (int i = 0; i < 1001; i++) {
		visit[i] = false;
	}

	queue<int> q;
	q.push(V);
	visit[V] = 1;
	cout << V << " ";
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[temp][i] == 1 && visit[i] != true) {
				q.push(i);
				cout << i << " ";
				visit[i] = 1;
			}
		}
	}
	cout << endl;
	return 0;
}