#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int P[100001][22];
int depth[100001];
vector<int> v[100001];
vector<int> ans;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


int main() {
	int N, M;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	depth[1] = 1;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < v[temp].size(); i++) {
			int cur = v[temp][i];
			if (depth[cur] == 0) {
				q.push(cur);
				P[cur][0] = temp;
				depth[cur] = depth[temp] + 1;
			}
		}
	}

	for (int j = 1; j <= 21; j++) {
		for (int i = 1; i <= N; i++) {
			if (P[i][j - 1] != 0)
				P[i][j] = P[P[i][j - 1]][j - 1];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;

		scanf("%d%d", &a, &b);

		if (depth[a] < depth[b])
			swap(a, b);

		int temp = depth[a] - depth[b];
		int cur = 0;
		while (temp > 0) {
			if (temp % 2) {
				a = P[a][cur];
			}
			cur++;
			temp /= 2;
		}

		if (a == b)
			ans.push_back(a);
		else {
			for (int k = 21; k >= 0; k--) {
				if (P[a][k] != P[b][k]) {
					a = P[a][k];
					b = P[b][k];
				}
			}
			ans.push_back(P[a][0]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
}
