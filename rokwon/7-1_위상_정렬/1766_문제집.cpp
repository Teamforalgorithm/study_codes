#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare{

	bool operator()(int i, int j) {
		return i > j;
	}
};

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int a, b;

	cin >> N >> M;

	int check[32001] = {0, };
	vector<int> arr[N+1];
	priority_queue<int, vector<int>, compare> q;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		check[b]++;
	}


	for (int i = 1; i <= N; i++){
		if (check[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if(q.empty())
			break;

		int x = q.top();
		q.pop();
		cout << x << ' ';

		for (int j = 0; j < arr[x].size(); j++) {
			if(--check[arr[x][j]] == 0)
				q.push(arr[x][j]);
		}
		
	}

	

	

	return 0;
}