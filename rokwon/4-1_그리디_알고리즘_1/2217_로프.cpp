#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

 using namespace std;

 int main(void){
     
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     int N, num = 0, sumarr = 0;
     cin >> N;
     vector<int> arr(N+1);
     
     for(int i = 0; i < N; i++) {
         cin >> arr[i];
     }
     
     sort(arr.begin(), arr.end(), greater<int>());
     
     num = 1;
     sumarr = arr[0];
     for(int i = 1; i < N; i++) {
         if (sumarr <= arr[i]*(i+1)) {
             sumarr = arr[i]*(i+1);
         }
     }
     
     cout << sumarr;
     
     return 0;
 }