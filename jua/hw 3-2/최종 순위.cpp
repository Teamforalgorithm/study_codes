#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int test, n, t, m, a, b;
int mat[501][501], order[501], indegree[501];

int main() {
	cin >> test;
	while (test--) {
		memset(mat, 0, sizeof(mat));
		memset(indegree, 0, sizeof(indegree));
		queue<int> q;
		queue<int> result;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> order[i];
		}
		//순위 - 인접 행렬 형식으로 그래프 생성, 진입차수 기록
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				mat[order[i]][order[j]] = 1;
				indegree[order[j]]++;
			}
		}
		//상대적인 순위가 바뀐 경우 계산
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (mat[a][b]) {
				mat[a][b] = 0; 
				mat[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				mat[b][a] = 0;
				mat[a][b] = 1;
				indegree[a]--;
				indegree[b]++;
			}
		}
		//진입 차수가 0인 노드들을 큐에 저장 
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) q.push(i);
		}
		bool certain = true;
		while (!q.empty()) {
			if (q.size() > 1) {
				certain = false;
				break;
			}
			int node = q.front();
			q.pop();
			result.push(node);
			for (int i = 1; i <= n; i++) {
				if (mat[node][i]) { //진입 경로가 있다면 
					indegree[i]--;
					if (indegree[i] == 0) q.push(i);
				}
			}
		}
		if (certain == false) cout << "?\n";
		else if (result.size() != n) cout << "IMPOSSIBLE\n";
		else {
			while (!result.empty()) {
				int node = result.front();
				result.pop();
				cout << node << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}