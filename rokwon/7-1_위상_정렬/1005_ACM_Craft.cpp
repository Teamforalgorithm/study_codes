#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while(T--) {

		int N, M, build_number;
		int a, b;

		cin >> N >> M;
		
		int check[1001] = {0, };
		vector<int> arr[N+1];
		vector<int> build_count(N+1);
		vector<int> minimum_build_sum_count(N+1, 0);
		queue<int> q;

		for (int i = 1; i <= N; i++)
			cin >> build_count[i];

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			check[b]++;
		}
		cin >> build_number;




		for (int i = 1; i <= N; i++){
			if (check[i] == 0) {
				minimum_build_sum_count[i] = build_count[i];
				q.push(i);
			}
		}

		for (int i = 0; i < N; i++) {

			int x = q.front();
			q.pop();
			

			for (int j = 0; j < arr[x].size(); j++) {
				minimum_build_sum_count[arr[x][j]] = max(minimum_build_sum_count[x]+build_count[arr[x][j]],minimum_build_sum_count[arr[x][j]]);
				if(--check[arr[x][j]] == 0)
					q.push(arr[x][j]);
			}

		}

		cout << minimum_build_sum_count[build_number] <<'\n';
	}
	

	

	return 0;
}