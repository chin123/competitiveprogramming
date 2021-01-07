#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<ull,ull> pui;

#define rep(x,n) for (int x = 0; x < n; x++)
#define dbg(x) cout << "x = " << x << endl
#define inp(t, v) t v; cin >> v
#define AR(t, ar, n) t ar[n]; for (int temp=0;temp<n;temp++) cin >> ar[temp]

#define ff first
#define ss second

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		inp(ull, n);
		AR(ull, ar, n);
		rep(i, n) {
			cout << ar[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
