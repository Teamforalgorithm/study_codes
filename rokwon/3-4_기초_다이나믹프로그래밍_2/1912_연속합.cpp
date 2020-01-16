#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int max_val;

	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0) {
			max_val = arr[0];
			continue;
		}

		if (arr[i - 1] + arr[i] > arr[i]) {
			arr[i] += arr[i - 1];
		}

		max_val = max(arr[i], max_val);
	}

	cout << max_val;


	return 0;
}


