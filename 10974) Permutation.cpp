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

int ARR[8];
vector<string> v;
int N;

void swap(int a, int b) {
	int temp = ARR[a];
	ARR[a] = ARR[b];
	ARR[b] = temp;
}

void recursive(int cur) {

	if (cur == 1) {
		string temp = "";
		for (int j = 0; j < N; j++) {
			temp += (ARR[j] + '0');
			temp += " ";
		}
		v.push_back(temp);
		return;
	}

	for (int i = 0; i < cur; i++) {
		swap(i, cur - 1);
		recursive(cur - 1);
		swap(i, cur - 1);
	}
}

int main() {

	cin >> N;

	for (int j = 0; j < N; j++) {
		ARR[j] = j + 1;
	}

	recursive(N);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		printf("\n");
	}
	return 0;

}