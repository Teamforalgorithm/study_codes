#include <iostream>
#include <math.h>
using namespace std;

int N;

void Hanoi(int n, int from, int to) {
	if (n == 0) return;
	Hanoi(n - 1, from, 6 - from - to); //1~n-1���� ž�� 2������ 
	cout << from << " " << to << "\n"; //�������� ����ִ°� 3������
	Hanoi(n - 1, 6 - from - to, to); //n-1���� 3������
}

int main() {
	cin >> N;
	int ans = (int)pow(2, N) - 1;
	cout << ans << "\n";
	Hanoi(N, 1, 3);
	return 0;
}