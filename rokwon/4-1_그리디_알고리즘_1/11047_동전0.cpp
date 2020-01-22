#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, num = 0;
    cin >> N >> K;

    vector<int> arr(N);

    for (int i = N-1; i >= 0; i--) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        num += K/arr[i];
        if (K % arr[i] == 0)
            break;
        else
            K = K % arr[i];
    }

    cout << num;



    return 0;
}