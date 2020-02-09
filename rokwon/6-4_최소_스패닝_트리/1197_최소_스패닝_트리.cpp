#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int V, E;
int check[10001];

struct connect{
	int x;
	int y;
	int count;
};

bool compare(const connect& i, const connect& j) {
	return i.count < j.count;
};

int find(int x) {
	if (x == check[x])
		return x;
	
	return check[x] = find(check[x]);
};

void merge(int x, int y) {
	check[find(x)] = y;
};

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	int count_sum = 0;

	cin >> V >> E;

	
	vector< connect > arr;

	for (int i = 1; i <= V; i++)
		check[i] = i;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		arr.push_back({a,b,c});
	}

	sort(arr.begin() , arr.end(), compare );

	connect vecon;

	for (int i = 0; i < E; i++) {
		vecon = arr[i];

		if(find(vecon.x) != find(vecon.y)) {
			merge(vecon.x, vecon.y);
			count_sum += vecon.count;
		}

	}

	cout << count_sum;

	return 0;
}