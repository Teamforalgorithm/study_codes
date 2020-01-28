#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int min_value = 2100000000;

	cin >> N;

	vector< vector<int> > arr(3, vector<int> (N,0));

	vector< vector<int> > sum_arr(3, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j][i];
		}
	}

	sum_arr[0][0] = arr[0][0];
	sum_arr[1][0] = arr[1][0];
	sum_arr[2][0] = arr[2][0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
				case 0:
					sum_arr[0][i] = min(sum_arr[1][i - 1]+arr[0][i], sum_arr[2][i - 1] + arr[0][i]);
					break;
				case 1:
					sum_arr[1][i] = min(sum_arr[0][i - 1] + arr[1][i], sum_arr[2][i - 1] + arr[1][i]);
					break;
				case 2:
					sum_arr[2][i] = min(sum_arr[0][i - 1] + arr[2][i], sum_arr[1][i - 1] + arr[2][i]);
					break;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (sum_arr[i][N - 1] < min_value)
			min_value = sum_arr[i][N - 1];
	}

	cout << min_value;




	return 0;
}


