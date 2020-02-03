#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int x;
    vector<int> LIS;
    cin >> N;

    LIS.push_back(-1000);

    for (int i = 0; i < N; i++) {
        cin >> x;

        if (LIS.back() < x)
            LIS.push_back(x);
        else {
            auto iter = lower_bound(LIS.begin(), LIS.end(), x);
            *iter = x;
        }

    }
    
    cout << LIS.size()-1;
    return 0;
}