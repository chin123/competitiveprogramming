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
		ans.clear();
		ind.clear();
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
		vector<pair<unsigned long long, unsigned long long>> prefs;
		ws.push({ar[0].second, ar[0].first});
		prefs.push_back(ws.top());
		for (int i = 1; i < n; i++) {
			ws.push({ar[i].second, ar[i].first});
			prefs.push_back(ws.top());
		}
		for (int i = 0; i < n; i++) {
			auto h = ar[i].first;
			auto w = ar[i].second;
			//cout << "looking " << h << "," << w << endl;
			auto it = lower_bound(ar, ar+n, pair<unsigned long long, unsigned long long>(h, 0));
			//cout << "found " << it->first << "," << it->second << endl;
			if (it != ar) {
				it--;
				//cout << "subtract: " << it->first << "," << it->second << endl;
				auto m = prefs[(it - ar)];
				//cout << "pref: " << m.first << "," << m.second << endl;
				if (m.second < ar[i].first && m.first < ar[i].second)
					ans[ar[i]] = ind[{m.second, m.first}];
			}
			//cout << "first pass: " << ans[ar[i]] << endl;
		}


		ws2.push({war[0].second, war[0].first});
		prefs.clear();
		prefs.push_back(ws2.top());
		for (int i = 1; i < n; i++) {
			ws2.push({war[i].second, war[i].first});
			prefs.push_back(ws2.top());
		}
		for (int i = 0; i < n; i++) {
			auto w = ar[i].first;
			auto h = ar[i].second;
			//cout << "looking " << w << "," << h << endl;
			auto it = lower_bound(war, war+n, pair<unsigned long long, unsigned long long>(w, 0));
			//cout << "found " << w << "," << h << " " << it->first <<","<< it->second << endl;
			if (it != war) {
				it--;
				//cout << "subtracted and reached " << it->first << ","<<it->second<<endl;
				auto m = prefs[(it - war)];
				//cout << "pref: " << m.first << "," << m.second << endl;
				if (m.second < ar[i].first && m.first < ar[i].second) {
					ans[ar[i]] = ind[m];
				}
				//cout << "second pass: " << ans[ar[i]] << endl;
			}
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
