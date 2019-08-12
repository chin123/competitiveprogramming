#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int pref[n+1];
		pref[0] = 0;
		//cout << "pref: " << pref[0] << ' ';
		for (int i = 0; i < n; i++) {
			pref[i+1] = pref[i]^ar[i];
			//cout << pref[i+1] << ' ';
		}
		//cout << endl;
		map<int, vector<int> > b;
		for (int i = 0; i < n+1; i++) {
			b[pref[i]].push_back(i);
		}
		int ans=0;
		for (auto p: b) {
			//cout << "in bucket " << p.first << endl;
			int size = p.second.size();
			int sum[size];
			sum[size-1] = p.second.back();
			//cout << "sum: " << sum[size-1] << ' ';
			for (int j = size-2; j >= 0; j--) {
				sum[j] = sum[j+1] + p.second[j];
				//cout << sum[j] << ' ';
			}
			//cout << endl;
			int contrib = 0;
			for (int j = 0; j < size-1; j++) {
				contrib -= (size-1-j)*p.second[j];
				contrib += sum[j+1];
				contrib -= (size-1-j);
			}
			//cout << "contrib is " << contrib << endl;
			ans += contrib;
		}
		cout << ans << endl;
	}
	return 0;
}
