#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int ar[n];
		for (int j = 0; j < n; j++) {
			cin >> ar[j];
		}
		sort(ar, ar+n);
		if (n == 2) {
			cout << 0 << endl;
			continue;
		} else {
			int steps = min(ar[n-1], ar[n-2]) - 1;
			if (steps <= 0) {
				cout << 0 << endl;
				continue;
			} else {
				int k = 0;
				for (int j = n-3; j >= 0 && k < steps; j--) {
					k++;
				}
				cout << k << endl;
			}
		}
	}
	return 0;
}
