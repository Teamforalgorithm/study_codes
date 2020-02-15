#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str1 = "";
	string str2 = "";
	
	int dp[1001][1001] = {0, };

	cin >> str1;
	cin >> str2;

	
	int length = 0;
	string ans = "";

	str1  = "1" + str1;
	str2  = "2" + str2;

	int index = str2.size()-1;

	

	for (int i = 1; i < str1.size(); i++) {
		for (int j = 1; j < str2.size(); j++) {
			if ( str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	length = dp[str1.size()-1][str2.size()-1];

	for (int i = str1.size()-1; i >= 1; i--) {
		for (int j = index; j >= 1; j--) {
			if (dp[i][j] == length && str1[i] == str2[j]) {
				ans = str1[i] + ans;
				index = j-1;
				length--;
				break;
			} 
		}
	}

	cout << dp[str1.size()-1][str2.size()-1] << '\n';
	cout << ans;



	return 0;
}