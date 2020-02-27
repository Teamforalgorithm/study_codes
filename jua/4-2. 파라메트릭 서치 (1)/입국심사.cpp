#include <iostream>
using namespace std;

int N, M;
long long arr[100000];

const long long MAX = 1000000000000000000LL;

bool possible(long long time) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += time / arr[i];
	}
	return cnt >= M;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	long long left = 0, right = MAX;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (possible(mid)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
	return 0;
}