#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
 
using namespace std;

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; 
    cin >> N;

    vector< vector<int> > arr(N, vector<int>(N,0));
    vector< vector<long long> > DP(N, vector<long long>(N,0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    DP[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(DP[i][j] != 0 && arr[i][j] != 0) {
                if(j + arr[i][j] < N)
                    DP[i][arr[i][j] + j] += DP[i][j];
                if(i + arr[i][j] < N)
                    DP[i+arr[i][j]][j] += DP[i][j];
            }
        }
    }

    cout << DP[N-1][N-1];
    
    return 0;
}