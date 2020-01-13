#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> arr(N, 0);
    
    for (int i = 0 ; i < N; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    cout << arr[0]*arr[N-1];
    
    
    return 0;
}
