#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		unsigned long long int w, h, n;
		cin >> w >> h >> n;
		int nw = 0, nh = 0;
		while (w % 2 == 0) {
			nw++;
			w /= 2;
		}
		while (h % 2 == 0) {
			nh++;
			h /= 2;
		}
		int p = 0;
		unsigned long long int temp = n;

		while (n >>= 1) {
			p++;
		}
		if (temp > (1<<p)) {
			p++;
		}
		if (p <= (nw+nh)) {
			cout<< "YES";
		} else {
			cout << "NO";
		}
		cout << endl;

	}
	return 0;
}
