#include<iostream>
#include<vector>
 
using namespace std;
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
 
    int K, N;

    cin >> K >> N;

    vector<long long> arr(N);

    long long max = 0;
    long long left, right;
    long long result = 0;

    for (int i = 0; i < K; i++){
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    left = 1;
    right = max;
 
    while (left <= right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < K; i++)
            sum += arr[i]/mid;
 
        if (sum >= N){
            if (result<mid)
                result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
 
    }

    cout << result;
 
    return 0;
}