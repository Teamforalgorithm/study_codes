#include <iostream>
using namespace std;

int N, P[48], S[48], card[48], ans = 0;

//ī�带 �� �� ���� ���� i��° ��ġ�� �ִ� ī��� S[i]��° ��ġ�� �̵��ϰ� �ȴ�.
//�� ī�尡 � �÷��̾�� ���� �ϴ����� ���� ������ P 

void shuffling() {
	int tmp[48];
	for (int i = 0; i < N; i++) {
		tmp[i] = card[i];
	}
	for (int i = 0; i < N; i++) {
		card[S[i]] = tmp[i];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		card[i] = P[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	bool check = true , success = false;
	while (check) {
		check = false, success = true;
		for (int i = 0; i <= N - 3; i += 3) {
			if (card[i] % 3 != 0) success = false;
			if (card[i + 1] % 3 != 1) success = false;
			if (card[i + 2] % 3 != 2) success = false;
		}
		if (success) break;
		shuffling();
		//�ʱ�� �������� �׸��α� 
		for (int i = 0; i < N; i++) {
			if (card[i] != P[i]) check = true;
		}
		ans++;
	}
	if (!success) cout << -1;
	else cout << ans;
	return 0;
}