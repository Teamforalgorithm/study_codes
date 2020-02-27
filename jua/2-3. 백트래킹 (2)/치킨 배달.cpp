#include <iostream>
#include <vector>
using namespace std;

int N, M; 
int arr[51][51];
int ans = 0x7FFFFFFF;
vector<pair<int, int>> chicken;
vector<pair<int, int>> p;

int distance(pair<int, int> a, pair<int, int> b)
{	
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(int cnt) {
	if (cnt == M) {

	}
	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				p.push_back(make_pair(i, j));
			else if (arr[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}