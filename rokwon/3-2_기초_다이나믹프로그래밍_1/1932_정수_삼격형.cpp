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

	vector< vector<int> > arr(N, vector<int> (N,0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == i) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
			}
		}
	}

	cout << *max_element(arr[N - 1].begin(), arr[N - 1].end());


	




	return 0;
}


