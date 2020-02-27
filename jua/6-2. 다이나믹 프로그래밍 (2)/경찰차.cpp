#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 0x7FFFFFFF;
int N, W;
pair<int, int> arr[1001];
int cache[1001][1001], ans[1001];

int getDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

//cache[x][y] = 경찰차 1이 x번째 사건을 경찰차 2가 y번째 사건을 마지막으로 처리하였을 때 이동한 거리의 합의 최솟값
int dp(int x, int y) {
	if (x == W || y == W) return 0;
	int &ret = cache[x][y];
	if (ret != -1) return ret;
	int event = max(x, y);
	int case1, case2;
	if (x == 0) {
		case1 = dp(event + 1, y) + getDist({ 1,1 }, arr[event + 1]);
	}
	else case1 = dp(event + 1, y) + getDist(arr[x], arr[event + 1]);
	if (y == 0) {
		case2 = dp(x, event + 1) + getDist({ N,N }, arr[event + 1]);
	}
	else case2 = dp(x, event + 1) + getDist(arr[y], arr[event + 1]);
	ret = min(case1, case2);
	if (case1 < case2) ans[event+1] = 1;
	else ans[event+1] = 2;
	return ret;
}
int main() {
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0) << "\n";
	for (int i = 1; i <= W; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}