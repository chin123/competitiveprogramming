#include <bits/stdc++.h>

using namespace std;
char p[100005], q[100005];
int ch[100005];

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		cin >> p;
		strcpy(q, p);
		int n = strlen(p);
		for (int i = 0; i < n+1; i++)
			ch[i] = 0;
		for (int i = 1; i < n; i++) {
			if (q[i] == q[i-1] && !ch[i-1]) {
				q[i] = (q[i]-'a' + 1)%26 + 'a';
				ch[i] = 1;
			}
			if (i != n-1 && q[i-1] == q[i+1] && !ch[i-1]) {
				q[i+1] = (q[i+1]-'a'+1)%26 + 'a';
				ch[i+1] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] != q[i])
				ans++;
		}
		cout << ans << endl;

	}
	return 0;
}
