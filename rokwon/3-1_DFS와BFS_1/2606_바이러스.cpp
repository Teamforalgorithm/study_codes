#include<iostream>
#include<queue>
#include<string>

using namespace std;

vector<int> arr[101];

int N, M;
bool check[101];

void BFS() {
	queue< int > q;
	int count = -1;
	q.push(1);

	while(!q.empty()) {
		int x = q.front();
		q.pop();

		if (!check[x]) {
			count++;
			check[x] = true;

			for (int i = 0; i < arr[x].size(); i++)
				q.push(arr[x][i]);
		}
	}

	cout << count;

}

int main(void) {

	cin >> N >> M;

	int a,b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	BFS();

	return 0;
}