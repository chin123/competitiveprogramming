#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar,ar+n, greater<>());
		map<int,int> b;
		for (int i = 0; i < n;i++) {
			b[ar[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (b[ar[i]+1] == 0) {
				b[ar[i]]--;
				b[ar[i]+1] = 1;
			}
		}
		int ans = 0;
		for (auto it: b) {
			ans += (it.second > 0);
		}
		cout << ans << endl;
	}
	return 0;
}
