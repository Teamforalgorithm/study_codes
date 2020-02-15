#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string str1;
	string str2;
	cin >> str1 >> str2;

	int arr[4001][4001];
	int maxlength = 0;

	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			if ( str1.at(j-1) == str2.at(i-1) ) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				maxlength = max(maxlength, arr[i][j]);
			}
		}
	}
	cout << maxlength;

	return 0;
}