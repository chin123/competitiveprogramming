#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n];
		for (int j=0;j<n;j++) {
			int tmp;
			cin>>tmp;
			tmp*=20;
			a[j]=tmp;
		}
		for (int j=0;j<n;j++) {
			int tmp;
			cin >> tmp;
			tmp *= -10;
			a[j]+=tmp;
			if (a[j]<0)a[j]=0;
		}
		cout << *(max_element(a,a+n)) << endl;
	}
	return 0;
}
