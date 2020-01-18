#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 0;

    cin >> N;

    vector<int> arr(N+1);
    vector<int> sum_arr(N+1);
    
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(i == 1 || i == 2) {
            sum_arr[i] = arr[i] + sum_arr[i-1];
        }
        else {
            num = max(arr[i]+arr[i-1]+sum_arr[i-3], arr[i]+sum_arr[i-2]);
            sum_arr[i] = max(num, sum_arr[i-1]);
        }
    }

    cout << max(sum_arr[N], sum_arr[N-1]);

    return 0;
}