#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L;

	int arr[102][102];
	int DP[102];
	int count = 0;
	bool boom = false;

	cin >> N >> L;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];



	for (int i = 0; i < N; i++ ) {
		for (int j = 0; j < N; j++) {

			if (boom == false) {
				if (j == 0)	DP[j] = 1;
				else if (arr[i][j] == arr[i][j-1])	DP[j] = DP[j-1]+1;
				else {
					if (arr[i][j] - arr[i][j-1] == 1 ) {
						if (DP[j-1] >= L)	DP[j] = 1;
						else	break;
					}
					else if (arr[i][j] - arr[i][j-1] == -1) {
						if (L != 1)	{
							boom = true;
							DP[j] = 1;
						}
						else {
							DP[j] = 0;
						}
						
					}
					else	break;		
				}
			}
			else {
				if (arr[i][j] == arr[i][j-1]) {
					DP[j] = DP[j-1]+1;
					if (L == DP[j]) {
						DP[j] = 0;
						boom =false;
					}
				}
				else break;
			}

			if ( j == N-1) {
				if (boom == true) {
					if (DP[j] < L)	break;
					else	count++;
				}
				else	count++;
			}
		}
		boom = false;
	}

	boom = false;

	for (int i = 0; i < N; i++ ) {
		for (int j = 0; j < N; j++ ) {

			if (boom == false) {
				if (j == 0 )	DP[j] = 1;
				else if (arr[j][i] == arr[j-1][i])	DP[j] = DP[j-1]+1;
				else {
					if (arr[j][i] - arr[j-1][i] == 1 ) {
						if (DP[j-1] >= L)	DP[j] = 1;
						else	break;
					}
					else if (arr[j][i] - arr[j-1][i] == -1) {
						if (L != 1)	{
							boom = true;
							DP[j] = 1;
						}
						else {
							DP[j] = 0;
						}
					}
					else	break;		
				}
			}
			else {
				if (arr[j][i] == arr[j-1][i]) {
					DP[j] = DP[j-1]+1;
					if (L <= DP[j]) {
						DP[j] -= L;
						boom =false;
					}
				}
				else break;
			}


			if ( j == N-1) {
				if (boom == true) {
					if (DP[j] < L)
						break;
					else
						count++;
				}
				else
					count++;
			}
				
		}
		boom = false;
	}

	cout << count;

	return 0;
}


