#include <iostream>
using namespace std;

int N;
int card[1001], cache[1001];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}
	cache[0] = 0;
	for (int i = 1; i <= N; i++) { //������ ī�� �ѿ� ���ؼ� 
		for (int j = i; j <= N; j++) { //�����Ϸ��� ī�� ������ ���� �ݾ��� �ִ� ����  
			cache[j] = max(cache[j], cache[j - i] + card[i]);
		}
	}
	cout << cache[N];
	return 0;
}