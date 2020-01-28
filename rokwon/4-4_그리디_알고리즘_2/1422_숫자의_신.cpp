#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<string>
 
using namespace std;

bool cmp(int i, int j) {
    return to_string(i)+to_string(j) > to_string(j)+to_string(i);
}

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> K >> N;

    int num = 0;
    string str = "";
    int max_value = 0;
    int point = 0;

    vector<int> arr(N);

    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        if (max_value < arr[i] )
            max_value = arr[i];
    } 
    sort(arr.begin(), arr.end(), cmp );

    for(int i = 0; i < K; i++) {
        if (arr[i] == max_value && point == 0) {
            for(int j = 0; j <= N-K; j++) {
                str = str + to_string(arr[i]);
            }
            point = 1;
        }
        else
            str = str + to_string(arr[i]);
    }

    cout << str;
    
    return 0;
}