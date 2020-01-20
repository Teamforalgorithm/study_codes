#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, max_val = 0;

    cin >> N;
    vector<int> arr(N+1);
    vector<int> sum_arr(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j<=N; j++) {
            sum_arr[j] = max(sum_arr[j], arr[i]+sum_arr[j-i]);
        }
    }
    cout << sum_arr[N];

    return 0;
}