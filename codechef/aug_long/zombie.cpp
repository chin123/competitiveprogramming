#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int l, int r, int value) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] += value;
		if (r&1) t[--r] += value;
	}
}

int query(int p) {
	int res = 0;
	for (p += n; p > 0; p >>= 1) res += t[p];
	return res;
}

void push() {
	for (int i = 1; i < n; ++i) {
		t[i<<1] += t[i];
		t[i<<1|1] += t[i];
		t[i] = 0;
	}
}

int main() {
	int k;
	cin>>k;
	for(int q=0;q<k;q++) {
		cin>>n;
		int c[n];
		int h[n];
		for (int i=0;i<n;i++) {
			cin >> c[i];
			t[n+i]=0;
		}
		for (int i=0;i<n;i++) {
			cin >> h[i];
		}
		build();
		for (int i =0 ; i < n; i++) {
			int l = max(0, i - c[i]);
			int r = min(i+c[i], n-1) + 1;
			modify(l, r, 1);
		}
		push();
		int newt[n];
		for (int i = 0; i < n; i++) {
			newt[i] = t[n+i];
		}
		sort(h,h+n);
		sort(newt,newt+n);
		bool no = false;
		for (int i = 0; i < n;i ++) {
			if (h[i] != newt[i]) {
				cout << "NO\n";
				no=true;
				break;
			}
		}
		if (!no) {
			cout << "YES\n";
		}
	}
}















