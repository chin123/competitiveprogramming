#include <bits/stdc++.h>

using namespace std;

char s[100005];

int main() {
	int t;
	cin >> t;
	for (int c=0;c<t;c++) {
		cin >>s;
		int len = strlen(s);
		priority_queue<int, vector<int>, greater<int>> ones;
		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				ones.push(i);
			}
		}
		while (!ones.empty()) {
			int ind = ones.top();
			ones.pop();
			if (s[ind] == '1') {
				s[ind] = '2';
				if (ind > 0 && s[ind-1] != '2') {
					s[ind-1] = (s[ind-1] == '0') ? '1': '0';
					if (s[ind-1] == '1') {
						ones.push(ind-1);
					}
				}
				if (ind < len - 1 && s[ind+1] != '2') {
					s[ind+1] = (s[ind+1] == '0') ? '1': '0';
					if (s[ind+1] == '1') {
						ones.push(ind+1);
					}
				}
			}
		}
		int no=0;
		for (int i = 0; i < len; i++) {
			if (s[i] != '2') {
				cout << "LOSE" <<endl;
				no=1;
				break;
			}
		}
		if (no == 0) {
			cout << "WIN" << endl;
		}
	}
	return 0;
}
