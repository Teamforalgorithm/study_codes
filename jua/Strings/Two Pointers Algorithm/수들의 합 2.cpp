#include <iostream>
using namespace std;

int N, M, arr[10000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = 0, sum = 0, lo = 0, hi = 0;
	while (true) {
		if (sum >= M) sum -= arr[lo++]; 
		else if (hi == N) break; //M �̻��� �ƴϰ� hi == N�̶�� �� �̻� ������ �Ұ���
		else sum += arr[hi++];
		if (sum == M) ans++;
	}
	cout << ans << "\n";
	return 0;
}