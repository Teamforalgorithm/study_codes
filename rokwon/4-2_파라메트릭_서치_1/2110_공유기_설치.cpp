#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    

    long long N , C;
    int count_C = 0;
    int jump = 0;

    long long max_value = 0;

    cin >> N >> C;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (max_value < arr[i])
            max_value = arr[i];
    }

    sort( arr.begin(), arr.end() );

    long long left = 1;
    long long right = max_value;

    long long result = 0;

    while (left <= right) {
        count_C = 0;
        long long mid = (left+right) / 2;
        jump = 0;

        for( int i = 0; i < N; i++) {
            if (jump <= arr[i]) {
                count_C++;
                jump = arr[i] + mid;
            }
        }
    
        if(count_C >= C) {
            if (result < mid) {
                result = mid;
            }
            left = mid +1;
        }
        else {
            right = mid -1;
        }

    }

    cout << result;
 
    return 0;
}