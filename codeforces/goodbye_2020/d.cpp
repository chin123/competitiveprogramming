#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		unsigned long long w[n];
		pair<unsigned long long, int> nodes[n];
		int deg[n];
		unsigned long long sum = 0;
		for (int i =0 ; i <n ;i ++) {
			cin >> w[i];
			sum += w[i];
			nodes[i] = pair<unsigned long long, int>{w[i], i};
			deg[i] = 0;
		}
		unordered_map<int,unordered_map<int, int>> gr;
		for (int i = 0; i < n-1; i++) {
			int u,v;
			cin >> u >> v;
			u--;
			v--;
			gr[u][v] = 1;
			gr[v][u] = 1;
			deg[u]++;
			deg[v]++;
		}

		cout << sum;
		sort(nodes, nodes+n, greater<>());
		int cur = 0;

		for (int i = 1; i < n-1; i++) {
			if (cur == n) {
				cout << ' ' << sum;
				continue;
			}
			int node = nodes[cur].second;
			int left = deg[node]-1;
			while (left == 0 && cur < n) {
				cur++;
				node = nodes[cur].second;
				left = deg[node]-1;
			}
			if (cur == n) {
				cout << ' ' << sum;
				continue;
			}
			int wt = w[node];
			sum += wt;
			cout << ' ' << sum;
			deg[node]--;
		}
		cout << endl;
	}
	return 0;
}
