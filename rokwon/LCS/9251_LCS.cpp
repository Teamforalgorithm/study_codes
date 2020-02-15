#include<iostream>
#include<string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
	str1 = "0" + str1;
	str2 = "0" + str2;
    int dp[1001][1001];
    
    for (int i = 1; i < str1.size(); i++) {
        for (int j = 1; j< str2.size(); j++) {
            if(str1[i] == str2[j]) {
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }                
        }
        
        
    }

	cout << dp[str1.size()-1][str2.size()-1];
    return 0;
    
}