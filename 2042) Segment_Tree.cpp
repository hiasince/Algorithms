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

long long NUM[1000000];
long long tree[4000000];

long long init(int left, int right, int index) {
	if (left == right) {
		tree[index] = NUM[left];
		return NUM[left];
	}
	else {
		return tree[index] = init(left, (left + right) / 2, index * 2) + init((left + right) / 2 + 1, right, index * 2 + 1);
	}
}

long long update(int left, int right, int where, int index, int value) {
	if (left == right) {
		if (where == left)
			tree[index] = value;
		return tree[index];
	}
	else {
		if (where <= (left + right) / 2)
			return tree[index] = update(left, (left + right) / 2, where, index * 2, value) + tree[index * 2 + 1];
		else
			return tree[index] = update((left + right) / 2 + 1, right, where, index * 2 + 1, value) + tree[index * 2];
	}
}

long long print(int left, int right, int destL, int destR, int index) {
	int mid = (left + right) / 2;

	if (left == destL && right == destR) {
		return tree[index];
	}
	else {
		if (destL <= mid && destR > mid)
			return print(left, mid, destL, mid, index * 2) + print(mid + 1, right, mid + 1, destR, index * 2 + 1);
		else if (destR <= mid)
			return print(left, mid, destL, destR, index * 2);
		else if (destL > mid)
			return print(mid + 1, right, destL, destR, index * 2 + 1);
		else
			return 0;
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> NUM[i];
	}

	init(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			update(1, N, b, 1, c);
		}
		else {
			cout << print(1, N, b, c, 1) << endl;
		}
	}


	return 0;
}



