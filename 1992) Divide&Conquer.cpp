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

char map[64][64];
string ans = "";

void Quad(int start_X, int start_Y, int N) {

	int com = map[start_Y][start_X];
	bool check = false;

	for (int i = start_Y; i < start_Y + N; i++) {
		for (int j = start_X; j < start_X + N; j++) {
			if (N >= 2 && map[i][j] != com) {
				check = true;
				break;
			}
		}
	}

	if (check) {
		ans += "(";
		if (N == 2) {
			for (int i = start_Y; i < start_Y + N; i++) {
				for (int j = start_X; j < start_X + N; j++) {
					ans += map[i][j];
				}
			}
		}
		else {
			Quad(start_X, start_Y, N / 2);
			Quad(start_X + N / 2, start_Y, N / 2);
			Quad(start_X, start_Y + N / 2, N / 2);
			Quad(start_X + N / 2, start_Y + N / 2, N / 2);
		}
		ans += ")";
	}
	else {
		ans += com;
	}

}


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	Quad(0, 0, N);

	cout << ans << endl;

	return 0;
}