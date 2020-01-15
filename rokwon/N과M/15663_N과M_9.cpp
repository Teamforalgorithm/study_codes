#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int N, M;
vector<int> print_arr;

void DFS(vector<int> arr, vector<int> visit_arr, int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << print_arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    set<int> s;
    for (int i = 0; i < N; i++) {    
        if(visit_arr[i] == 0) {
            visit_arr[i] = 1;

            if ( s.find(arr[i]) == s.end()) {
                s.insert(arr[i]);    
                print_arr[count] = arr[i];
                DFS(arr,visit_arr, count+1);
            }
            visit_arr[i]=0;
        }   
    }

}

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> arr(N, 0);
    vector<int> visit_arr(N, 0);

    print_arr.resize(8);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    DFS(arr, visit_arr, 0);
    


    return 0;
}