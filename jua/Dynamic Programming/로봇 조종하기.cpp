#include <iostream>
using namespace std;

const int MIN = -0x3f3f3f;
int N, M, mars[1001][1001];
bool visited[1001][1001];
int ans = MIN, cache[1001][1001];
int dir[3][2] = { {0,-1},{0,1},{1,0} };

int max(int a, int b) { return a > b ? a : b; }

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//cache: ���� �ڸ����� ���� �� �ִ� �ִ� ��ġ�� �� 
int dfs(int y, int x) {
	if (y == N && x == M) return mars[y][x];
	if (y > N || y < 1 || x > M || x < 1) return MIN;
	int& ret = cache[y][x];
	if (ret != MIN) return ret;
	for (int i = 0; i < 3; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		ret = max(ret, dfs(ny, nx) + mars[y][x]);
		visited[ny][nx] = 0;
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mars[i][j];
			cache[i][j] = MIN;
			visited[i][j] = 0;
		}
	}
	visited[1][1] = 1;
	cout << dfs(1, 1);
	return 0;
}