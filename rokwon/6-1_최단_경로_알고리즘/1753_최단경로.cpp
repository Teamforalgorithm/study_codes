#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

vector< pair<int,int> > arr[20001];
int min_distan[20001];
int V,E,K;

void dijkstra() {
    priority_queue< pair<int,int> > q;
    q.push({0, K});

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

};

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;

    cin >> V >> E >> K;
    V++;

    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
    }
    for (int i = 1; i < V; i++)
        min_distan[i] = 210000000;


    dijkstra();

    for(int i = 1; i < V; i++) {
        if (min_distan[i] == 210000000 )
            cout << "INF" << '\n';
        else
            cout << min_distan[i] << '\n';
    }

    return 0;
}