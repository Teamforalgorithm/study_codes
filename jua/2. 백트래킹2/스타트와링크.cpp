#include <iostream>
#include <vector>
using namespace std;

int N; 
int arr[21];
int p[21][21];
bool visited[21];
int ans = 0x7FFFFFFF;

void dfs(int cnt) {
	vector<int> link, start;
	if (cnt == N / 2) {
		for (int i = 0; i < N; i++) {
			if (arr[i]) start.push_back(i);
			else link.push_back(i);
		}
		int ss = 0, sl = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				ss += p[start[i]][start[j]] + p[start[j]][start[i]];
				sl += p[link[i]][link[j]] + p[link[j]][link [i]];
			}
		}
		if (abs(ss - sl) < ans) ans = abs(ss - sl);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr[cnt] = i;
		dfs(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> p[i][j];
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}