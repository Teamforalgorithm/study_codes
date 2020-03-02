#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int test, n, t, m, m1, m2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> test;
	while (test--) {
		int ran[501];
		bool pos[501][501];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ran[i];
		}
		cout << ran[1] << ran[2];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				pos[ran[i]][ran[j]] = true;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << pos[i][j] << " ";
			}
			cout << "\n";
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> m1 >> m2; //상대적인 등수가 바뀜 
			if (pos[m1][m2]) { 
				pos[m1][m2] = false;
				pos[m2][m1] = true;
			}
			else { 
				pos[m1][m2] = true;
				pos[m2][m1] = false;
			}
		}
		//이긴 횟수 세기 
		int sum[501];
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (pos[i][j]) sum[i]++;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << pos[i][j] << " ";
			}
			cout << "\n";
		}
		
		bool check[501];
		int newRank[501];
		bool possible = true, same = true;
		memset(check, false, sizeof(check));
		//새로운 등수 계산
		for (int i = 1; i <= n; i++) {
			newRank[n + 1 - sum[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (check[newRank[i]]) possible = false;
			else check[newRank[i]] = true;
			if (ran[i] != newRank[i]) same = false;
		}
		if (same && m != 0) cout << "?\n";
		else if (!possible) cout << "IMPOSSIBLE\n";
		else {
			for (int i = 1; i <= n; i++) {
				cout << newRank[i] << " ";
			}
		}
		cout << "\n";
		
	}
}