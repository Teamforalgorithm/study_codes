#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

int N,M; 
int arr[501][501];
int DP[501][501];
int px[4] = {-1, 1, 0 , 0};
int py[4] = {0, 0, -1, 1};


int DFS(int x, int y) {
    if( x == 0 && y == 0)
        return 1;

    
    if(DP[x][y] == -1) {
        DP[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int next_x = px[i] + x;
            int next_y = py[i] + y;
            if ( next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
                if (arr[x][y] < arr[next_x][next_y]) {
                    DP[x][y] += DFS(next_x, next_y);
                }
            }
        }
    }


    return DP[x][y];
} 

 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            DP[i][j] = -1;
        }
    }

    cout << DFS(M-1, N-1);
    
    return 0;
}