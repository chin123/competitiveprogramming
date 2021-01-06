#include <bits/stdc++.h>

using namespace std;
pair<unsigned long long,unsigned long long> ar[200005];
pair<unsigned long long,unsigned long long> war[200005];
pair<unsigned long long,unsigned long long> orig[200005];
map<pair<unsigned long long,unsigned long long>,int> ans;
map<pair<unsigned long long,unsigned long long>,int> ind;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			unsigned long long h,w;
			cin >> h >> w;
			ar[i] = pair<unsigned long long, unsigned long long>{h,w};
			war[i] = pair<unsigned long long, unsigned long long>{w,h};
			orig[i] = pair<unsigned long long, unsigned long long>{h,w};
			ans[ar[i]] = -1;
			ind[ar[i]] = i;
		}
		sort(ar,ar+n);
		sort(war,war+n);
		priority_queue<pair<unsigned long long, unsigned long long int>, vector<pair<unsigned long long, unsigned long long int>>, greater<pair<unsigned long long, unsigned long long int>> > ws;
		priority_queue<pair<unsigned long long, unsigned long long int>, vector<pair<unsigned long long, unsigned long long int>>, greater<pair<unsigned long long, unsigned long long int>> > ws2;
		vector<pair<unsigned long long, unsigned long long>> temp;
		ws.push({ar[0].second, ar[0].first});
		for (int i = 1; i < n; i++) {
			if (temp.size() != 0 && ar[i].first > temp.back().first) {
				for (auto m: temp) {
					ws.push({m.second, m.first});
				}
				temp.clear();
			}
			auto m = ws.top();
			if (m.second < ar[i].first && m.first < ar[i].second) {
				ans[ar[i]] = ind[{m.second, m.first}];
			}
			temp.push_back(ar[i]);
		}

		temp.clear();

		ws2.push({war[0].second, war[0].first});
		for (int i = 1; i < n; i++) {
			if (temp.size() != 0 && war[i].first > temp.back().first) {
				for (auto m: temp) {
					ws2.push({m.second, m.first});
				}
				temp.clear();
			}
			auto m = ws2.top();
			if (m.second < war[i].second && m.first < war[i].first) {
				ans[{war[i].second, war[i].first}] = ind[m];
			}
			temp.push_back(ar[i]);
		}

		for (int i = 0; i < n; i++) {
			if (ans[orig[i]] != -1) {
			cout << ans[orig[i]]+1<< ' ';
			} else {
				cout << -1 << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
