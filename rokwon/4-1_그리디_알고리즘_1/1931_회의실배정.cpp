#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool a(vector<int>& i, vector<int>& j){
    return i[0] < j[0];
}

bool b(vector<int>& i, vector<int>& j) {
    return i[1] < j[1];
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 0, end_val = 0;
    int x, y;

    cin >> N;

    vector< vector<int> > arr(N ,vector<int>(2));

    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    sort( arr.begin(), arr.end(), a );
    sort( arr.begin(), arr.end(), b );
    
    end_val = arr[0][1];
    num++;

    for (int i = 1; i < N; i++) {
        if ( end_val <= arr[i][0] ){
            num++;
            end_val = arr[i][1];
        }
    }

    cout << num;

    return 0;
}