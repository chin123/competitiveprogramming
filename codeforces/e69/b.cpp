#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	list<int> ar;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ar.push_back(t);
	}
	auto curit = max_element(ar.begin(), ar.end());
	while (*curit != 1) {
		if (true) {
			auto it_copy = curit;
			it_copy++;
			if (it_copy == ar.end()) {
			} else if (*(it_copy) == *curit - 1) {
				(*curit)--;
				ar.erase(it_copy);
				continue;
			}
		}
		if (curit != ar.begin()) {
			auto it_copy = curit;
			it_copy--;
			if (*(it_copy) == *curit - 1) {
				(*curit)--;
				ar.erase(it_copy);
				continue;
			}
		}
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}
