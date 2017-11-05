#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

vector<int> v[10001];		//정방향 벡터
vector<int>	r_v[10001];		//역방향 벡터
bool visit[10001];			//visit 배열
vector<int> ans[10001];		//SCC 벡터
stack<int> st;				//리턴 후 넣을 스택

void dfs(int index) {
	for (int i = 0; i < v[index].size(); i++) {
		if (!visit[v[index][i]]) {
			visit[v[index][i]] = true;
			dfs(v[index][i]);
		}
	}
	st.push(index);
	return;
}

void r_dfs(int index) {
	for (int i = 0; i < r_v[index].size(); i++) {
		if (visit[r_v[index][i]]) {
			visit[r_v[index][i]] = false;
			r_dfs(r_v[index][i]);
		}
	}
	ans[st.top()].push_back(index);

	if (ans[index].empty())
		ans[index].push_back(INT_MAX);
	return;
}


int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		r_v[b].push_back(a);
	}

	visit[1] = true;
	dfs(1);
	int count = 0;

	while (!st.empty()) {
		visit[st.top()] = false;
		if (ans[st.top()].empty()) {
			r_dfs(st.top());
			count++;
		}
		sort(ans[st.top()].begin(), ans[st.top()].end());
		st.pop();
	}
	cout << count << endl;
	for (int i = 0; i <= N; i++) {
		int min_v = INT_MAX;
		int min_index = -1;
		for (int q = 0; q <= N; q++) {
			if (!ans[q].empty() && ans[q][0] < min_v) {
				min_v = ans[q][0];
				min_index = q;
			}
		}
		if (!ans[min_index].empty() && ans[min_index][0] != INT_MAX) {
			for (int j = 0; j < ans[min_index].size(); j++) {
				cout << ans[min_index][j] << " ";
			}
			cout << -1 << endl;
			ans[min_index].clear();
		}
	}
	return 0;
}