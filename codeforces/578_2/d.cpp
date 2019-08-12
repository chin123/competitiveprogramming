#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	char ar[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	int num[n][n];
	int numr[n][n];
	for (int i = 0; i < n; i++) {
		num[0][i] = (ar[0][i] == 'B')? 1: 0;
		numr[i][0] = (ar[i][0] == 'B')? 1: 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num[i][j] = (ar[i][j] == 'B')? 1: 0;
			num[i][j] += num[i-1][j];
			numr[j][i] = (ar[j][i] == 'B')? 1: 0;
			numr[j][i] += numr[j][i-1];
		}
	}
	int maxr, maxc;
	int cr=0, cc=0;
	for (int i = 0; i < k; i++) {
		if (num[k-1][i] == num[n-1][i]) {
			cc++;
		}
		if (num[i][k-1] == num[i][n-1]) {
			cr++;
		}
	}
	maxr=cr;
	maxc=cc;
	for (int i = 0; i < n-k; i++) {
		for (int j = 1; j < n-k; j++) {
			int prevrow = numr[i][j-1];
			if (j-1 != 0 && j-1-k >= 0) {
				prevrow -= numr[i][j-1-k];
			}
			int prevcol = num[i][j-1];
			if (i > 0) {
				prevcol -= num[i-1][j-1];
			}
			if (prevrow == num[i][n-1]) {
				cr--;
			}
			if (prevcol = num[n-1][j-1]) {
				cc--;
			}
			int newrow = numr[i+k-1][j];
			if (j-k >= 0) {
				newrow -= numr[i][j-k];
			}
			int newcol = num[i+k-1][j];
			if (i > 0) {
				newcol -= num[i-1][j];
			}
			if (num[])
		}
	}
	return 0;
}
