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

int ARR[1001];

void swap(int a, int b) {
	int temp = ARR[a];
	ARR[a] = ARR[b];
	ARR[b] = temp;
}

void quicksort(int S, int E) {
	if (S >= E)
		return;
	int p = S;
	int j = S;
	for (int i = S + 1; i <= E; i++) {
		if (ARR[p] > ARR[i]) {
			j++;
			swap(i, j);
		}
	}
	swap(j, p);
	p = j;

	quicksort(S, p - 1);
	quicksort(p + 1, E);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ARR[i];
	}

	quicksort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << ARR[i] << endl;
	}

	return 0;
}