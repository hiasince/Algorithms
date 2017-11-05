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
	u = find(u);    //������ ��Ʈ�� ã�´�.
	v = find(v);

	if (u == v)     //��Ʈ�� ���ٸ� �̹� ���� ����
		return;

	// u�� v���� �� ���� Ʈ����� swap
	if (level[u] > level[v])
		swap(u, v); // �׻� u�� �� ���� Ʈ���� �ǵ��� �Ѵ�.

					// u�� ��Ʈ�� v�� �ǵ���
	parent[u] = v;

	// u�� v�� ���̰� ���� �� v�� ���̸� �÷��ش�.
	if (level[u] == level[v])
		level[v]++;
}

int main() {
	int N, M;
	cin >> N >> M;

	// ó���� ��Ʈ�� �ڱ� �ڽ�, ������ 1
	for (int i = 0; i <= 200; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			if (j > i && temp == 1)      //���� �۾��� ���� �ʵ��� j > i �϶��� ����
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

		if (start != find(val))     //���� ������ �ƴ� ���
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