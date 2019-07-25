#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n,k;
		cin >> n >> k;
		unsigned long long a[n];
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		vector<int> pos;
		unsigned long long rs = 0;
		for (int j = 0; j < n; j++) {
			rs += a[j];
			if (rs % 2 == 1) {
				pos.push_back(j);
				rs = 0;
			}
		}
		int num = pos.size();
		if ((num - (k-1)) % 2 == 0 || k > num) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int j = 0; j < k-1; j++) {
				cout << pos[j] + 1 << ' ';
			}
			cout << n << endl;
		}
	}
	return 0;
}
