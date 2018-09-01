#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int p[1001];

double dist(pair<double, double> a, pair<double, double> b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int find(int a) {
	if (p[a] == a)
		return a;
	else
		return p[a] = find(p[a]);
}

void uni(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	p[roota] = rootb;
}

struct three {
	int a, b;
	double c;
};

bool compare(three a, three b) {
	return a.c < b.c;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		double N, E;
		double ans = 0;
		cin >> N;
		vector<pair<int, int>> v;
		vector<three> v2;
		
		for (int i = 1; i <= N; i++) {
			int a;
			scanf("%d", &a);
			v.push_back({ a,0 });
			p[i] = i;
		}

		for (int i = 0; i < N; i++) {
			int a;
			scanf("%d", &a);
			v[i].second = a;
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				v2.push_back({ i + 1,j + 1,dist(v[i], v[j]) });
			}
		}

		sort(v2.begin(), v2.end(), compare);

		int size = v2.size();

		for (int i = 0; i < size; i++) {
			if (find(v2[i].a) != find(v2[i].b)) {
				ans += v2[i].c;
				uni(v2[i].a, v2[i].b);
			}
		}

		cin >> E;
		cout << setprecision(0) << fixed << "#" << t << " " << ans * E << "\n";
		
	}

	return 0;
}
