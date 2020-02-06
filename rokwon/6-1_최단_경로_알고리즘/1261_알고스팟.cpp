#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

typedef struct{
    int fir;
    int sec;
    int count;
}all_for;

int N, M;
int arr[101][101];
int value[101][101];

struct compare{
    bool operator()(const all_for& i, const all_for& j) {
        return i.count < j.count;
    };
};

void dijkstra() {

    priority_queue< all_for, vector<all_for>, compare > q;
    q.push({0,0,0});

    while(!q.empty()) {

        int x = q.top().fir;
        int y = q.top().sec;
        int count = -q.top().count;

        if(value[x][y] > count) {
            value[x][y] = count;

            if(x-1 >= 0) {
                if(arr[x-1][y] == 1)
                    q.push({x-1, y, -(count+1)});
                else
                    q.push({x-1, y, -count});
            }
            if(M > x+1) {
                if(arr[x+1][y] == 1)
                    q.push({x+1, y, -(count+1)});
                else
                    q.push({x+1, y, -count});
            }
            if(y-1 >= 0) {
                if(arr[x][y-1] == 1)
                    q.push({x, y-1, -(count+1)});
                else
                    q.push({x, y-1, -count});
            }
            if(N > y+1) {
                if(arr[x][y+1] == 1)
                    q.push({x, y+1, -(count+1)});
                else
                    q.push({x, y+1, -count});
            }

        }

        q.pop();
    }


}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string str;

    for (int i = 0; i < M; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j]-'0';
            value[i][j] = 2100000000;
        }
    }

    dijkstra();

    cout << value[M-1][N-1];


    return 0;
}