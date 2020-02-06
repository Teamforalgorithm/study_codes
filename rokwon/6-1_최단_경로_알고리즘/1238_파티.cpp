#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

int sum_distan[1001];

int N,M,X;

void dijkstra( vector< pair<int,int> > arr[]) {

    priority_queue< pair<int,int> > q;
    q.push({0, X});

    int min_distan[1001];

    for (int i = 1; i < N; i++)
        min_distan[i] = 210000000;
    

    while(!q.empty()) {
        
        int vertex = q.top().second;
        int cost = -q.top().first;

        if ( cost < min_distan[vertex] ) {
            min_distan[vertex] = cost;

            for (int i = 0; i < arr[vertex].size(); i++)
                q.push({ -(arr[vertex][i].second+cost), arr[vertex][i].first});
            
        }
        q.pop();
    }

    for(int i = 1; i < N; i++)
        sum_distan[i] += min_distan[i];

};

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;

    cin >> N >> M >> X;
    N++;

    vector< pair<int,int> > arr[1001];
    vector< pair<int,int> > back_arr[1001];

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
        back_arr[b].push_back({a,c});
    }

    dijkstra(arr);
    dijkstra(back_arr);

    int ans = *max_element(sum_distan, sum_distan+N);

    cout << ans;


    return 0;
}