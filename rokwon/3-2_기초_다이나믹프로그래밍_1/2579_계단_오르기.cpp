#include<iostream>
#include<vector>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int left;
    int right;
    vector<int> arr(301, 0);
    vector<int> sum_arr(301, 0);

    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    sum_arr[1] = arr[1];

    for(int i = 2; i <= N; i++) {
        if (i == 2) {
            sum_arr[i] = arr[i]+sum_arr[i-1];
        }
        else {
            left = arr[i]+arr[i-1]+sum_arr[i-3];
            right = arr[i]+sum_arr[i-2];
            sum_arr[i] = left > right ? left : right;
        }
        
    }

    cout << sum_arr[N];




    return 0;
}