#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    int max_value = 0;

    cin >> N >> M;

    int arr[1001][1001];
    int DP[1001][1001];
    

    string str;
    

    for(int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 1; j <= M; j++)
            arr[i][j] = str[j-1] - '0';
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j<= M; j++) {
            if ( arr[i][j] == 1) {
                if ( DP[i-1][j] != 0 && DP[i][j-1] != 0 && DP[i-1][j-1] != 0 ) {
                    if ( DP[i-1][j] == DP[i][j-1] && DP[i-1][j] == DP[i-1][j-1])
                        DP[i][j] = DP[i-1][j]+1;
                    else{
                        DP[i][j] = min(DP[i][j-1], min(DP[i-1][j], DP[i-1][j-1])) + 1;   
                    }

                }
                else
                    DP[i][j] = 1;

                max_value = max(max_value, DP[i][j]);

            }
            else {
                DP[i][j] = 0;
            }

        }
    }

    cout << pow(max_value,2);





    return 0;
}