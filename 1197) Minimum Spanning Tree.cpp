#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int ARR[26];

int main() {
	string a,ans;
	ans = "";
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		ARR[a[i] - 'A']++;
	}
	
	int check = 0;
	int center = -1;
	int index = 0;
	for (int i = 0; i < 26; i++) {
		if (check == 2) {		//Ȧ���� 2�� �̻��� ���
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
		else {
			if (ARR[i] % 2 == 1) {
				check += 1;
				for (int j = 0; j < ARR[i] - 1; j++) {
					ans.insert(ans.begin() + index, i + 'A');
				}
				index += ARR[i] / 2;
				center = i;
			}
			else {
				for (int j = 0; j < ARR[i]; j++) {
					ans.insert(ans.begin() + index, i + 'A');
				}
				index += ARR[i] / 2;
			}
		}
	}
	
	//Ȧ�� �������� ���ĺ� ����� �ֱ�
	if (check == 1) {
		ans.insert(ans.begin() + index, center + 'A');
	}

	//2�� ������ ���
	if(ans.size() < 2)
		cout << "I'm Sorry Hansoo" << endl;
	else
		cout << ans << endl;


	return 0;
}
