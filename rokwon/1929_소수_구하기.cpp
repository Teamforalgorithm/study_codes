#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int M,N;
    vector<int> arr(1000001, 0);
    cin >> M >> N;
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i = 2; i <= N; i++) {
        for (int j = 2; i*j <= N; j++)
            arr[i*j] = 1;
    }
    
    for (int i = M; i <= N; i++) {
        if(arr[i] == 0)
            cout << i << '\n';
    }
    
    return 0;
}
