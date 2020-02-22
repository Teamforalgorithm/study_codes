#include <iostream>
using namespace std;

int N, L;
int map[100][100];
int visited[100][100];
int ans = 0;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool check = true;
			if (j==0 || map[i][j] == map[i][j-1]) visited[i][j] = 1;
			if (map[i][j] - map[i][j - 1] == 1) {
				for (int k = 1; k <= L; k++) {
					if (j - k < 0 || visited[i][j - k] == 2 || map[i][j] - map[i][j - k] != 1) {
						check = false;
						break;
					}
				}
				if (check) {
					for (int k = 1; k <= L; k++) {
						visited[i][j - k] = 2;
					}
					visited[i][j] = 1;
					ans++; 
					continue;
				}
			}
			else if (map[i][j] - map[i][j - 1] == -1) {
				check = true;
				for (int k = 1; k <= L; k++) {
					if (j + k >= N || map[i][j] - map[i][j + k] != 1) {
						check = false;
						break;
					}
					visited[i][j + k] = 2;
				}
				if (check) {
					for (int k = 1; k <= L; k++) {
						visited[i][j + k] = 2;
					}
					visited[i][j] = 1;
					ans++;
				}
			}
			if (check == false) break;
		}
		cout << ans << "\n";
		print();
	}
	return 0; 
}