#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int N, M;
int arr[1001][1001];

struct arr_info
{
    int i;
    int j;
    int count;
    int warn;
};

int visit_arr[1001][1001][2];

void BFS() {
    int value;

    queue<arr_info> q;
    q.push({0,0,1,0});

    int count = 0;

    arr_info info;

    while(!q.empty()) {

        info = q.front();

        if(info.i == N-1 && info.j == M-1) {
            cout << info.count;
            count = 1;
            break;
        }
        if(info.i >= 0 && info.i < N && info.j >= 0 && info.j < M) {
            if(visit_arr[info.i][info.j][1] == 1 && visit_arr[info.i][info.j][0] == 1) {
                q.pop();
                continue;
            }
            else {
                if(arr[info.i][info.j] == 1) {
                    info.warn++;
                }

                if(info.warn < 2) {
                    if(visit_arr[info.i][info.j][1] == 0 && info.warn == 1) {
                        visit_arr[info.i][info.j][1] = 1;
                        q.push({info.i+1 , info.j , info.count+1 , info.warn});
                        q.push({info.i-1 , info.j , info.count+1 , info.warn});
                        q.push({info.i , info.j+1 , info.count+1 , info.warn});
                        q.push({info.i , info.j-1 , info.count+1 , info.warn});
                    }
                    else if (visit_arr[info.i][info.j][0] == 0 && info.warn == 0){
                        visit_arr[info.i][info.j][0] = 1;
                        q.push({info.i+1 , info.j , info.count+1 , info.warn});
                        q.push({info.i-1 , info.j , info.count+1 , info.warn});
                        q.push({info.i , info.j+1 , info.count+1 , info.warn});
                        q.push({info.i , info.j-1 , info.count+1 , info.warn});
                    }
                }
            }
        }
        q.pop();
    }
    if (count == 0) {
        cout << -1;
    }



    
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string str;

    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            arr[i][j] = str[j] -'0';
        }
    }

    if(N == 1 && M == 1) {
        cout << 1;
        return 0;
    }

    BFS();

    

    return 0;
}