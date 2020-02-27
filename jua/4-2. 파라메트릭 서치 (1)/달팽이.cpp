#include <iostream>
#include <climits>
using namespace std;

long long A, B, V;
int ans = 0;
int main() {
	cin >> A >> B >> V; 
	int h = 0; 
	while (true) {
		h += A; 
		ans++;
		if (h == V) break;
		h -= B;
	}
	cout << ans; 
	return 0;
}