#include<iostream>
#include<vector>
#include<utility>
 
using namespace std;

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long min_value = 1000000001;
    long long sum = 0;

    cin >> N;

    pair<int, int> arr[N];

    for (int i = 0; i < N-1; i++)
        cin >> arr[i].first;
    arr[N-1].first = 0;

    for (int i = 0; i < N; i++)
        cin >> arr[i].second;


    for (int i = 0; i < N-1; i++) {
        if(min_value > arr[i].second) {
            min_value = arr[i].second;
        }
        sum += min_value*arr[i].first;
    }

    cout << sum;


    

    return 0;
}