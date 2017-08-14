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

long long N, K;

int BS(int left, int right)
{
	if (left > right)
		return left;

	int mid = (left + right) / 2;
	long long count = 0;

	for (int i = 1; i <= N; i++) {
		if (mid >= N * i)
			count += N;
		else
			count += mid / i;
	}

	if (count < K)
		return BS(mid + 1, right);
	else
		return BS(left, mid - 1);
}

int main() {

	cin >> N >> K;

	int ans = BS(1, K);

	cout << ans << endl;

	return 0;
}