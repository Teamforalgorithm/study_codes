#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector<int> arr(N+1, 0);
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 1] + arr[i-2]*2) % 10007;
	}

	cout << arr[N];


	return 0;
}


