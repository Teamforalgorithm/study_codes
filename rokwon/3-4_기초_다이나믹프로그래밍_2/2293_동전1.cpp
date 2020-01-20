#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, num;

    cin >> N >> K;

    vector<int> arr(K+1);
    
    for(int i = 1; i <= N; i++) {
        cin >> num;
        for(int j = 1; j <= K; j++) {
            if(j > num)
                arr[j] += arr[j-num];
            else if(j == num)
                arr[j]++;
        }
    }

    cout << arr[K];

    return 0;
}