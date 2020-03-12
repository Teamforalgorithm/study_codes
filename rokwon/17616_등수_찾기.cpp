#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, X;

bool check[100001];

int BFS(vector<int> arr[]) {
    int this_count = 0;

    queue<int> q;
    q.push(X);
    while(!q.empty() ) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < arr[now].size(); i++) {
            int value = arr[now][i];
            if (check[value] == false) {
                check[value] = true;
                q.push(value);
                this_count++;
            }
        }
    }

    return this_count;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector< int > arr[100001];
    vector< int > reverse_arr[100001];

    int a,b;

    cin >> N >> M >> X;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[b].push_back(a);
        reverse_arr[a].push_back(b);
    }

    cout << BFS(arr)+1 << ' ' << N-BFS(reverse_arr);

    return 0;
}