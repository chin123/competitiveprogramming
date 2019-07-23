#include <iostream>
#include <cstring>

#define PMOD 998244353

typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	char a[n][11];
	for (int i = 0; i < n; i++) {
		char t[11];
		cin >> t;
		int sl = strlen(t);
		int j;
		for (j = 0; j < 10 - sl; j++) {
			a[i][j] = '0';
		}
		for (int count = 0; count < sl; count++) {
			a[i][j++] = t[count];
		}
		a[i][10] = '\0';
		cout << a[i] << ' ';
	}
	cout << endl;
	int len = strlen(a[0]);
	long long int sum[len*2];
	for (int i = 0; i < len; i++) {
		long long int temp = 0;
		for (int j = 0; j < n; j++) {
			temp += (a[j][i] - '0');
			temp %= PMOD;
		}
		sum[2*i] = temp;
		sum[2*i+1] = temp;
	}
	for (int i = 0; i < 2*len; i++) {
		sum[i] = (sum[i]*n)%PMOD;
	}
	long long power = 1;
	long long ans = 0;
	for (int i = len*2 - 1; i >= 0; i--) {
		ans += sum[i]*power;
		ans %= PMOD;
		power*=10;
		power%=PMOD;
	}
	cout << ans << endl;
}
