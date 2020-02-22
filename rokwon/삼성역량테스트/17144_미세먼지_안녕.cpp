#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int R,C,T;
vector< vector<int>  > arr;
pair<int,int> top_air;
pair<int,int> down_air;

int d[4][2] = { {0 , 1}, {-1, 0}, {0, -1}, {1, 0} };

void implementation() {

	vector< vector<int> > change_arr( R, vector<int>(C, 0) );
	change_arr[top_air.first][top_air.second] = -1;
	change_arr[down_air.first][down_air.second] = -1;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) {
				int count = 0;

				for (int k = 0; k < 4; k++) {
					int new_i = i + d[k][0];
					int new_j = j + d[k][1];
					
					if(new_i >= 0 && new_i < R && new_j >=0 && new_j < C && change_arr[new_i][new_j] != -1) {
						count++;
						change_arr[new_i][new_j] += arr[i][j] / 5;
					}
				}

				change_arr[i][j] += arr[i][j]-(arr[i][j]/5)*count;
			}
		}
	}
	arr = change_arr;

	int x = top_air.first;
	int y = top_air.second;
	int direct = 0;
	int have = 0;

	while(1) {
		int new_x = x + d[direct][0];
		int new_y = y + d[direct][1];

		if (new_x == top_air.first && new_y == top_air.second)
			break;

		if (new_x >= 0 && new_x < R && new_y >=0 && new_y < C ) {
			swap(have, arr[new_x][new_y]);
			x = new_x;
			y = new_y;
		}
		else
			direct = (direct+1)%4;
	}

	x = down_air.first;
	y = down_air.second;
	direct = 0;
	have = 0;

	while(1) {
		int new_x = x + d[direct][0];
		int new_y = y + d[direct][1];

		if (new_x == down_air.first && new_y == down_air.second)
			break;

		if (new_x >= 0 && new_x < R && new_y >=0 && new_y < C ) {
			swap(have, arr[new_x][new_y]);
			x = new_x;
			y = new_y;
		}
		else
			direct = (direct+3)%4;
	}



}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;

	arr.resize(R);
	for (int i = 0; i < R; i++)
		arr[i].resize(C);

	bool top_ok = false;
	int ans = 2;

	for ( int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if ( arr[i][j] == -1) {
				if (top_ok == false){
					top_air = {i,j};
					top_ok = true;
				}
				else
					down_air = {i,j};
			}
		}
	}

	for(int i = 0; i < T; i++)
		implementation();

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans += arr[i][j];

	cout << ans;








	return 0;
}