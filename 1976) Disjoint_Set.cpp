#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
using namespace std;

int parent[201];
int level[201];

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int find(int p)
{
	if (p == parent[p])
		return p;
	return parent[p] = find(parent[p]);
}

void Union(int u, int v)
{
	u = find(u);    //각각의 루트를 찾는다.
	v = find(v);

	if (u == v)     //루트가 같다면 이미 같은 집합
		return;

	// u가 v보다 더 깊은 트리라면 swap
	if (level[u] > level[v])
		swap(u, v); // 항상 u가 더 작은 트리가 되도록 한다.

					// u의 루트가 v가 되도록
	parent[u] = v;

	// u와 v의 깊이가 같을 때 v의 깊이를 늘려준다.
	if (level[u] == level[v])
		level[v]++;
}

int main() {
	int N, M;
	cin >> N >> M;

	// 처음엔 루트가 자기 자신, 레벨은 1
	for (int i = 0; i <= 200; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			if (j > i && temp == 1)      //같은 작업을 하지 않도록 j > i 일때만 실행
				Union(i, j);
		}
	}

	bool check = true;
	int val;
	scanf("%d", &val);

	int start = find(val);
	for (int i = 0; i < M - 1; i++)
	{
		scanf("%d", &val);

		if (start != find(val))     //같은 집합이 아닌 경우
		{
			check = false;
			break;
		}
	}

	if (check)
		cout << "YES";
	else
		cout << "NO";

}