#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
	int x;
	int y;
	int count;
};

int N, M;

vector< info > arr;
vector<int> weight(501);
vector<int> check(501);

void Bellman_Ford() {


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < arr.size(); j++) {
			int x = arr[j].x;
			int y = arr[j].y;
			int count = arr[j].count;

			if (weight[x] != 2100000000) {
				if (weight[y] > weight[x]+count)
					weight[y] = weight[x]+count;
			}

		}
	}

	check = weight;

	//이걸 수행해서 check = weight 같지 않다면 음의 사이클이 있다는거 
	// 음의 사이클이 있으면수행할 때마다 바뀌기 때문
	for (int i = 0; i <= arr.size(); i++) {
		int x = arr[i].x;
		int y = arr[i].y;
		int count = arr[i].count;

		if (check[x] != 2100000000) {
			if (check[y] > check[x]+count)
				check[y] = check[x]+count;
		}
	}

	//음의 사이클 있을 시 바로 짤
	for (int i = 1; i <= N; i++) {
		if(check[i] != weight[i]) {
			cout << -1;
			return;
		}
	}

	//음의 사이클 없으면 최단경로 값을 출력 
	for (int i = 2; i<= N; i++) {
		if (weight[i] == 2100000000)
			cout << -1 << '\n';
		else
			cout << weight[i] << '\n';
	}

	
	


};

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int a,b,c;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		arr.push_back({a,b,c});
	}

	weight[1] = 0;
	for(int i = 2; i <= N; i++) {
		weight[i] = 2100000000;
	}

	Bellman_Ford();

	
	return 0;
}