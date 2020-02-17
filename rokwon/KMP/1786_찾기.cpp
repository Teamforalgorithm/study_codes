#include<iostream>
#include<string>
#include<vector>

using namespace std;

void make_fail(string P, vector<int>& fail){

	int j = 0;

	for (int i = 1; i < P.size(); i++) {
		while(j > 0 && P[i] != P[j])
			j = fail[j-1];
		if (P[i] == P[j])
			fail[i] = ++j;
	}

}


int main(void) {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string T = "";
	string P = "";

	getline(cin, T);
	getline(cin, P);

	vector<int> fail(P.size(), 0);
	vector<int> print_index;

	make_fail(P, fail);

	int count = 0;
	int j = 0;
	int index = 0;

	for (int i = 0; i < T.size(); i++) {
		while (j >0 && T[i] != P[j])
			j = fail[j-1];
		if (T[i] == P[j]) {
			if( j == P.size()-1) {
				count++;

				print_index.push_back(i - j + 1);
				j = fail[j];
			}
			else
				j++;
		}
		
	}

	cout << count << '\n';
	for (int i = 0; i < print_index.size(); i++) {
		cout << print_index[i] << ' ';
	}


	return 0;
}