#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		int ar[n];
		int s1 = 0;
		int s2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i] == 1) {
				s1++;
			} else {
				s2++;
			}
		}
		int f = 1;
		int sum = s1 + 2*s2;
		if (sum % 2 == 1) {
			f = 0;
		} else {
			f = 0;
			for (int i = 0; i <= s1; i++) {
				int k = i;
				int rem = (sum/2) - k;
				if (rem % 2 == 0) {
					if ((rem/2) <= s2) {
						if ((s1-k) + (2*s2 - rem) == sum/2) {
							f = 1;
							break;
						}
					}
				}
			}
		}
		if (f == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
