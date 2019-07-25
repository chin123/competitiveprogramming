#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i <q; i++) {
		int n,k;
		cin >> n >> k;
		char s[n+1];
		cin >> s;
		char rot[3] = {'R', 'G', 'B'};
		char r[k], g[k], b[k];
		for (int j = 0; j < k; j++) {
			r[j] = rot[j%3];
			g[j] = rot[(j+1)%3];
			b[j] = rot[(j+2)%3];
		}
		int minr=0, ming=0, minb=0;
		for (int j = 0; j < k; j++) {
			if (s[j] != r[j])
				minr++;
			if (s[j] != g[j])
				ming++;
			if (s[j] != b[j])
				minb++;
		}
		int pr=minr,pg=ming,pb=minb;
		for (int j = 1; j <= n-k; j++) {
			int tr=pb, tg=pr, tb=pg;
			if (s[j-1] != b[0])
				tr--;
			if (s[j-1] != r[0])
				tg--;
			if (s[j-1] != g[0])
				tb--;
			if (s[j-1+k] != r[k-1]) {
				tr++;
			}
			if (s[j-1+k] != g[k-1]) {
				tg++;
			}
			if (s[j-1+k] != b[k-1]) {
				tb++;
			}
			pr=tr;
			pg=tg;
			pb=tb;
			minr=min(minr,pr);
			ming=min(ming,pg);
			minb=min(minb,pb);
		}
		cout << min(minr, min(minb, ming)) << endl;
	}
	return 0;
}
