#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int N, M;
int arr[1001][1001];
int count_0;

struct apple{
    int i;
    int j;
    int num;
};

queue< apple > q;

void BFS() {

    
    apple pro;
    while(!q.empty()) {

        pro = q.front();
        pro.num++;
        if(pro.i >= 0 && pro.i < N && pro.j >= 0 && pro.j < M) {
            if(arr[pro.i][pro.j] == 0) {
                arr[pro.i][pro.j] = pro.num;
                count_0--;
                if (count_0 == 0) {
                    cout << pro.num-1;
                    break;
                }
                q.push({pro.i+1,pro.j,pro.num});
                q.push({pro.i-1,pro.j,pro.num});
                q.push({pro.i,pro.j+1,pro.num});
                q.push({pro.i,pro.j-1,pro.num});
            }
        }
        
        q.pop();
    }
    if(count_0 != 0) {
        cout << -1;
    }



    
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    count_0 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                count_0++;
            }
            else if(arr[i][j] == 1) {
                arr[i][j] = 0;
                q.push({i,j,0});
                count_0++;
            }
        }
    }

    BFS();

    return 0;
}