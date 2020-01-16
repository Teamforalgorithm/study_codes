#include <iostream>
#include <vector>
using namespace std;

int s[9][9];
vector<pair<int, int>> v;

bool check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (s[x][i] == num) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (s[i][y] == num) return false;
	}
	x = x / 3;
	y = y / 3;
	for (int i = x * 3; i < (x * 3) + 3; i++) {
		for (int j = y * 3; j < (y * 3) + 3; j++) {
			if (s[i][j] == num) return false;
		}
	}
	return true;
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> s[i][j];
			if (s[i][j] == 0) v.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		for (int i = 0; i < 9; i++) {
			if (check(x, y, i)) {
				s[x][y] = i;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << s[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}