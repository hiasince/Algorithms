#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <climits>
using namespace std;

char alpa[21] = { 'b','d','e','f','g','h','j',
'k','l','m','o','p','q','r',
's','u','v','w','x','y','z' };

int input[50] = { 0 };
int T;
int maxv = 0;

void choose(int N, int index, int state) {
	if (N == 0) {
		int count = 0;
		for (int i = 0; i < T; i++) {
			if ((input[i] & state) == input[i]) {
				count++;
			}
		}
		if (count > maxv)
			maxv = count;
		return;
	}
	if (20 - index >= N)
		choose(N, index + 1, state);
	choose(N - 1, index + 1, state | (1 << (alpa[index] - 97)));

}

int main() {
	int K;

	int abc = 0;
	//acnit은 무조건
	abc |= 1 << ('a' - 97);
	abc |= 1 << ('c' - 97);
	abc |= 1 << ('n' - 97);
	abc |= 1 << ('t' - 97);
	abc |= 1 << ('i' - 97);

	cin >> T >> K;

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}
	else {
		K -= 5;

		for (int i = 0; i < T; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j <temp.size(); j++) {
				input[i] |= 1 << (temp[j] - 97);
			}
		}
	}

	choose(K, 0, abc);

	cout << maxv << endl;

	return 0;
}