#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long int n, k;
	cin >> n >> k;
	long long ans = n - (-3 + sqrt(9+8*(n+k)))/2;
	cout << ans << endl;
}
