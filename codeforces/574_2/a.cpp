#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int fav[n];
	int numf[k];
	int ans = 0;
	int maxn = (n+1)/2;
	for (int i = 0; i < k; i++) {
		numf[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> fav[i];
		fav[i]--;
		numf[fav[i]]++;
		if (numf[fav[i]] == 2 && maxn > 0) {
			ans += 2;
			maxn--;
			numf[fav[i]] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (numf[i] == 1 && maxn > 0) {
			ans += 1;
			maxn--;
		}
	}
	cout << ans << endl;

	return 0;
}
