#include<iostream>

using namespace std;

int N, M;
int ans;
int arr[51][51];

pair<int,int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int confirm_d(int x, int y, int di) {
	int part_count = 0;
	bool back_ok = false;

	for (int i = 0; i < 4; i++) {
		int new_x = x+d[i].first;
		int new_y = y+d[i].second;

		if( arr[new_x][new_y] == 1 || arr[new_x][new_y] == 2 ) {
			part_count++;
			if(i == (di+2)%4 && arr[new_x][new_y] == 2)
				back_ok = true;
		}

	}

	if (part_count == 4 && back_ok == true)
		return 3;	//뒤로가라
	else if (part_count == 4)
		return 10;	//끝내라
	else
		return 1;	//다른거 진행

}

void BFS(int a, int b, int di) {

	ans++;
	arr[a][b] = 2;

	while(1) {

		int confirm = confirm_d(a,b,di);

		if(confirm == 10)
			break;
		else if ( confirm == 3) {
			int new_di = (di+2)%4;

			a += d[new_di].first;
			b += d[new_di].second;
		}
		else {
			di = (di+3)%4;	//왼쪽으로 방향전환

			int left_a = a + d[di].first;
			int left_b = b + d[di].second;
			
			if (arr[left_a][left_b] == 0) {
				a = left_a;
				b = left_b;

				arr[a][b] = 2;
				ans++;
			}

		}
		
		
	}

	cout << ans;

};

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	int x, y, di;
	ans = 0;

	cin >> x >> y >> di;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	BFS(x,y,di);


	return 0;
}