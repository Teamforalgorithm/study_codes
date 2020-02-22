#include<iostream>
#include<vector>

using namespace std;

int N;
int ans;

int line_wei[10001];
vector< pair<int, int> > arr[10001];

void BFS() {
	vector<int> q;

	int value = 0;

	q.push_back(1);
	
	while(value < N-2) {
		int x = q[value++];
		
		for (int i = 0; i < arr[x].size(); i++)
			q.push_back(arr[x][i].first);
	}

	while(!q.empty()) {
		int x = q.back();
		q.pop_back();

		int max_line_wei = 0;

		int first_max = 0;
		int second_max = 0;
		for(int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i].first;
			int count = arr[x][i].second;

			max_line_wei = max(line_wei[y]+count, max_line_wei);

			if(first_max < line_wei[y]+count) {
				second_max = first_max;
				first_max = line_wei[y]+count;
			}
			else if (second_max < line_wei[y]+count)
				second_max = line_wei[y]+count;
		}
		line_wei[x] = max_line_wei;
		ans = max(ans, first_max+second_max);
	}
}

int main(void) {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	ans = 0;
	int a,b,c;

	for (int i = 0; i < N-1; i++) {
		cin >> a >> b >> c;

		arr[a].push_back({b,c});
	}

	BFS();

	cout << ans;


	return 0;
}