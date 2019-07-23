#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	long long int aa, ab;
	aa = a[n-1];
	ab = b[n-1];
	for (int i = n - 2; i >= 0; i--) {
		long long int taa = max(a[i] + ab, a[i] + aa - a[i+1]);
		long long int tab = max(b[i] + aa, b[i] + ab - b[i+1]);
		aa = taa;
		ab = tab;
	}
	cout << max(aa,ab) << endl;
	return 0;
}
