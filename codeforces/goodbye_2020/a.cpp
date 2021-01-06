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
			cin >>ar[i];
		}
		unordered_set<int> k;
		for (int i =0;i < n; i++) {
			for (int j = i+1; j < n; j++) {
				int are = abs(ar[i]-ar[j]);
				k.insert(are);
			}
		}
		cout << k.size() << endl;
	}
	return 0;
}
