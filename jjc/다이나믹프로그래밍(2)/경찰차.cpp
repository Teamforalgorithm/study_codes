#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
const int MAXN = 1001;
const int INF = 1e9;
 
struct incident {
	int y, x;
};
 
struct info {
	int pos, choice;
};
 
int n, w;
int dp[MAXN][MAXN]; // 첫번째차 i번째사건, 두번째차 j번째사건
incident inc[MAXN];
info path[MAXN][MAXN];
 
// 해당 사건에 대해 경찰차량의 거리를 반환하는 함수, dir에 따라 첫번째, 두번째 차량의 거리 반환
int dist(int y, int x, int m, bool dir) {
	if (dir)
		return abs(inc[m].y - (y == 0 ? 1 : inc[y].y)) + abs(inc[m].x - (y == 0 ? 1 : inc[y].x));
	else
		return abs(inc[m].y - (x == 0 ? n : inc[x].y)) + abs(inc[m].x - (x == 0 ? n : inc[x].x));
}
 
int backtrack(int y, int x) {
	// 기저 조건 : 모든 사건 해결완료
	if (y == w || x == w)
		return 0;
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	int car1, car2, mx = max(y, x) + 1;
 
	// 백트래킹으로 현재 위치 차량이 움직였을 경우 최소 값을 얻는다.
	car1 = backtrack(mx, x) + dist(y, x, mx, true);
	car2 = backtrack(y, mx) + dist(y, x, mx, false);
	// 2차원경로 압축 저장
	if (car1 < car2) {
		path[y][x].pos = mx * MAXN + x;
		path[y][x].choice = 1;
	}
	else {
		path[y][x].pos = y * MAXN + mx;
		path[y][x].choice = 2;
	}
	// 어떤 차량으로 갈때가 최소인지
	return ret = min(car1, car2);
}
 
// 저장해놓은 path를 통해 출력
void print(int y, int x) {
	if (y == w || x == w)
		return;
	cout << path[y][x].choice << '\n';
	int ny = path[y][x].pos / MAXN, nx = path[y][x].pos % MAXN;
	print(ny, nx);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -1);
	cin >> n;
	cin >> w;
	for (int i = 1; i <= w; ++i)
		cin >> inc[i].x >> inc[i].y;
	cout << backtrack(0, 0) << '\n';
	print(0, 0);
	return 0;
}