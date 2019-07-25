#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int b,w;
		cin >> b >> w;
		if (b > w) {
			if (b <= 4 + 2*(w-1)+1) {
				cout << "YES" << endl;
				long long x=2,y=2;
				while (w > 0) {
					cout << x << ' ' << y << endl;
					cout << x << ' ' << y+1 << endl;
					w--;
					b--;
					y+=2;
				}
				if (b>0) {
					cout << 2 << ' ' << 1 << endl;
					b--;
				}
				x=2,y=2;
				while (b>0) {
					cout << x-1 << ' ' << y << endl;
					b--;
					if (b>0) {
						cout << x+1 << ' ' << y << endl;
						b--;
					}
					y+=2;
				}
			} else {
				cout << "NO" << endl;
			}
		} else {
			if (w <= 4 + 2*(b-1)+1) {
				cout << "YES" << endl;
				long long x=2,y=3;
				while (b > 0) {
					cout << x << ' ' << y << endl;
					cout << x << ' ' << y+1 << endl;
					w--;
					b--;
					y+=2;
				}
				if (w>0) {
					cout << 2 << ' ' << 2 << endl;
					w--;
				}
				x=2,y=3;
				while (w>0) {
					cout << x-1 << ' ' << y << endl;
					w--;
					if (w>0) {
						cout << x+1 << ' ' << y << endl;
						w--;
					}
					y+=2;
				}
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
