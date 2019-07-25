#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		int maxx=100000, maxy=100000, minx=-100000, miny=-100000;
		for (int j = 0; j < n; j++) {
			int x,y;
			int left, up, right, down;
			cin >> x >> y >> left >> up >> right >> down;
			if (left == 0) {
				minx = max(minx, x);
			}
			if (right == 0) {
				maxx = min(maxx, x);
			}
			if (up == 0) {
				maxy = min(maxy, y);
			}
			if (down == 0) {
				miny = max(miny, y);
			}
		}
		if (maxx >= minx && maxy >= miny) {
			cout << 1 << ' ' << minx << ' ' << miny << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
