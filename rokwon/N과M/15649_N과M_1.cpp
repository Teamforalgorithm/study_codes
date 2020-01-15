#include<iostream>
#include<vector>

using namespace std;

int N;
int M;

void NM(vector<int> arr, vector<int> check, int end) {

	if (end == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == 1)
			continue;
		arr[end] = i;
        check[i] = 1;
		NM(arr, check, end + 1);
		check[i] = 0;
	}
}

int main(void) {

	cin >> N >> M;
	vector<int> arr(M, 0);
	vector<int> check(N + 1, 0);

	NM(arr, check, 0);

	return 0;
}
