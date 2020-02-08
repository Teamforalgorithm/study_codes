#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

void BFS_check(vector<int> arr[],vector<int> arr2[] ,int num) {
	queue<int> q;
	q.push(num);
	int check[101] = {0, };

	while (!q.empty()) {
		int x = q.front();

		if( check[x] == 0) {
			check[x] = 1;
			for (int i = 0; i < arr[x].size(); i++)
				q.push(arr[x][i]);
		}
		q.pop();
	}

	q.push(num);
	int check_2[101] = {0, };

	while (!q.empty()) {
		int x = q.front();

		if (check_2[x] == 0) {
			check_2[x] = 1;
			for (int i = 0; i < arr2[x].size(); i++)
				q.push(arr2[x][i]);
		}
		q.pop();
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0 && check_2[i] == 0)
			count++;
	}

	cout << count << '\n';

}

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> N >> M;

	vector<int> this_arr[101];
	vector<int> that_arr[101];

	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		this_arr[a].push_back(b);
		that_arr[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		BFS_check(this_arr, that_arr, i);


	return 0;
}