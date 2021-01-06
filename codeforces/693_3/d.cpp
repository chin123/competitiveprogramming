#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		unsigned long long ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar+n, greater<>());
		unsigned long long a=0,b=0;
		for (int i = 0; i < n; i++) {
			if (ar[i] % 2 == 0 && i % 2 == 0) {
				a+=ar[i];
			}
			if (ar[i] % 2 == 1 && i % 2 == 1) {
				b+=ar[i];
			}
		}
		if (a > b)
			cout << "Alice"<<endl;
		if (b>a)
			cout << "Bob"<<endl;
		if (a==b)
			cout << "Tie"<<endl;


	}
	return 0;
}
