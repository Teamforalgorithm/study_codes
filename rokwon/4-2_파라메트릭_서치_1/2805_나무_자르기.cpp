#include<iostream>
#include<vector>
 
using namespace std;
 
int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int M, N;

    cin >> N >> M;
    int max = 0;
    long long left, right;
    long long result = 0;

    vector<int> arr(N);
 
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    left = 0;
    right = max;
 
    while (left <= right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
            if (mid < arr[i])
                sum += arr[i]-mid;
 
        if (sum >= M){
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