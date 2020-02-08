#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[101][101];
	int N, M;
	int x, y, cou;
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 2100000000;
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> cou;
		arr[x][y] = min(arr[x][y], cou);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int z = 1; z <= N; z++) {
				if (j == z) continue;
				if ( arr[j][i] != 2100000000 && arr[i][z] != 2100000000 )
					arr[j][z] = min(arr[j][i] + arr[i][z] , arr[j][z]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(arr[i][j] == 2100000000)	cout << 0 << ' ';
			else	cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}