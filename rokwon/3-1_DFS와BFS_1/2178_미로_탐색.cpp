#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct info {
	int i;
	int j;
	int count;
};

int N, M;
int arr[101][101];
bool check[101][101];

void BFS() {
	queue< info > q;
	q.push({0,0,1});

	while(!q.empty()) {
		int x = q.front().i;
		int y = q.front().j;
		int count = q.front().count;
		q.pop();

		if (x == N-1 && y == M-1) {
			cout << count;
			break;
		}		

		if (!check[x][y]) {
			check[x][y] = true;
			if(x-1 >= 0 && arr[x-1][y] != 0)
				q.push({x-1, y, count+1});
			if(x+1 < N && arr[x+1][y] != 0)
				q.push({x+1, y, count+1});
			if(y-1 >= 0 && arr[x][y-1] != 0)
				q.push({x, y-1, count+1});
			if(y+1 < M && arr[x][y+1] != 0)
				q.push({x, y+1, count+1});
		}
	}

}

int main(void) {

	cin >> N >> M;

	string str = "";

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++)
			arr[i][j] = str[j] - '0';
	}

	BFS();

	return 0;
}