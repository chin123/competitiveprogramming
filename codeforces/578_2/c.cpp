#include <bits/stdc++.h>

using namespace std;

unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return (a*b)/__gcd(a,b);
}

int main() {
	unsigned long long n,m,q;
	cin >> n >> m >> q;
	unsigned long long int b = lcm(lcm(n,m)/n, lcm(n,m)/m);
	unsigned long long int pa = lcm(n,m)/n, pb = lcm(n,m)/m;
	for (int i = 0; i < q; i++) {
		unsigned long long sx,sy,ex,ey;
		cin >> sx >> sy >> ex >> ey;
		unsigned long long gx, gy;
		sy--;
		ey--;
		if (sx == 1) {
			gx = (pa*sy)/b;
		} else {
			gx = (pb*sy)/b;
		}
		if (ex == 1) {
			gy = (pa*ey)/b;
		} else {
			gy = (pb*ey)/b;
		}
		if (gx == gy) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}
	return 0;
}
