#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	long long int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	if (k == 1) {
		cout << ar[n-1] - ar[0] << endl;
		return 0;
	}
	vector<pair<long long int,int>> gap;
	long long int pref[n-1];
	for (int i = 0; i < n-1; i++) {
		gap.push_back(pair<long long int,int>(ar[i+1]-ar[i], i));
	}
	sort(gap.begin(), gap.end());
	vector<int> gappos;
	for (int i = 0; i < k-1; i++) {
		gappos.push_back(gap[gap.size()-1-i].second);
	}
	sort(gappos.begin(), gappos.end());
	long long int ans = ar[gappos[0]] - ar[0];
	for (int i = 1; i < gappos.size(); i++) {
		ans += ar[gappos[i]] - ar[gappos[i-1]+1];
	}
	ans += ar[n-1] - ar[gappos.back()+1];
	cout << ans << endl;
	return 0;
}
