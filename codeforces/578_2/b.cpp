#include <bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin>>t;
	for (int c= 0; c < t; c++) {
		long long int n,m,k;
		cin >> n >> m >> k;
		long long int col[n];
		for (int i = 0; i < n; i++) {
			cin >> col[i];
		}
		bool fail=false;
		for (int i = 0; i < n-1; i++) {
			if (col[i] >= col[i+1]-k) {
				m += col[i] - max((long long) 0, col[i+1]-k);
			} else {
				if (m >= (col[i+1]-k-col[i])) {
					m -= col[i+1]-k-col[i];
				} else {
					fail=true;
					break;
				}
			}
		}
		if (fail) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
