#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int num;

void DFS(vector< vector<int> >& arr, vector<int>& visit_arr, int v, int n) {
	if (visit_arr[v] == 0) {
		cout << v << ' ';
		num++;
		visit_arr[v] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1 && visit_arr[i] != 1) {
			DFS(arr, visit_arr, i, n);
		}
		
	}
}

void BFS(vector< vector<int> > arr,queue<int> q, vector<int> visit_arr, int v, int n) {
	visit_arr[v] = 1;

	while (q.empty() != true) {
		cout << q.front() << ' ';
		
		for (int i = 1; i <= n; i++) {
			if (arr[q.front()][i] == 1 && visit_arr[i] != 1) {
				q.push(i);
				visit_arr[i] = 1;
			}
		}
		q.pop();
	}

}

int main(void) {

	int N, M, V;

	cin >> N >> M >> V;
	int point1, point2;

	vector< vector<int> > arr(N+1, vector<int>(N+1, 0));
	vector<int> visit_arr(N+1, 0);
	vector<int> b_visit_arr(N+1, 0);
	queue<int> q;

	for (int i = 0; i < M; i++) {
		cin >> point1 >> point2;
		arr[point1][point2] = 1;
		arr[point2][point1] = 1;
	}

	DFS(arr, visit_arr, V, N);
	cout << '\n';
	q.push(V);
	BFS(arr, q, b_visit_arr, V, N);

	return 0;
}
