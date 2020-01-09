#include<iostream>
#include<vector>

using namespace std;

int num;

void allsum(vector<int> arr, int sum, int cur_sum ,int index) {
    
    if( sum == cur_sum + arr[index])
        num++;
    if( index == arr.size()-1 )
        return;
    
    allsum(arr, sum, cur_sum, index+1);
    allsum(arr, sum, cur_sum+arr[index], index+1);
    
}

int main(void) {
    int N, sum;
    
    cin >> N >> sum;
    
    vector<int> arr(N, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    allsum(arr, sum, 0, 0);
    
    cout << num;
    
    return 0;
}
