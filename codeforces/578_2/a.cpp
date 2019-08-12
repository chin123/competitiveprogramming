#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	char s[n];
	cin >> s;
	char b[11];
	for (int i = 0; i < 10; i++) {
		b[i] = '0';
	}
	int l=0,r=0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			for (int j = 0; j < 10; j++) {
				if (b[j]=='0') {
					b[j]='1';
					break;
				}
			}
		} else if (s[i] == 'R') {
			for (int j = 9; j >= 0; j--) {
				if (b[j]=='0') {
					b[j]='1';
					break;
				}
			}
		} else {
			b[s[i]-'0'] = '0';
		}
	}
	b[10]='\0';
	cout << b << endl;
	return 0;
}
