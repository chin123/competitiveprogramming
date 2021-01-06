#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unsigned long long> dp;
unsigned long long int ar[200005];


unsigned long long solve(int i, int n) {
	if (i >= n) {
		return 0;
	}
	if (dp.find(i) != dp.end()) {
		return dp[i];
	}
	dp[i] = ar[i] + solve(i+ar[i], n);
	return dp[i];
}

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		dp.clear();
		unsigned long long ans = 0;
		for (int i = 0; i < n; i++) {
			unsigned long long k = solve(i, n);
			ans = max(ans, k);
		}
		cout << ans << endl;

	}
	return 0;
}
