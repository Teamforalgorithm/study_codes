#include <iostream>
#include <string.h>
using namespace std;

int N, L;
int arr[100][100], arr2[100][100], road[100][100];
int ans = 0;

void cnt(int arr[][100]) {
	for (int i = 0; i < N; i++) {
		bool fail = false;
		for (int j = 0; j < N; j++) {
			if (j == 0 || arr[i][j - 1] == arr[i][j]) continue;
			else if (arr[i][j-1] + 1 == arr[i][j]) { //�ö󰡴� ���� 
				if (j < L) {
					fail = true;
					continue;
				}
				for (int k = 1; k <= L; k++) {
					//�ٸ� ���ΰ� ������ �ȵǰ�, ���̰� ���ƾ� �� 
					if (road[i][j - k] == -1 && arr[i][j - k] == arr[i][j - 1]){
						road[i][j - k] = 1;
					}
					else {
						fail = true;
						break;
					}
				}
			}
			else if (arr[i][j - 1] == arr[i][j] + 1) { //�������� ���� 
				if (j + L > N) {
					fail = true;
					continue;
				}
				for (int k = 0; k < L; k++) {
					if (road[i][j + k] == -1 && arr[i][j + k] == arr[i][j]) {
						road[i][j + k] = 1;
					}
					else {
						fail = true;
						break;
					}
				}
			}
			else fail = true; //���� ���� ���̰� 1�̻� ���� ���
			if (fail) break;
		}
		if (!fail) {
			ans++;
		}
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr2[j][i] = arr[i][j];
		}
	}
	memset(road, -1, sizeof(road));
	cnt(arr);
	memset(road, -1, sizeof(road));
	cnt(arr2);
	cout << ans << "\n";
	return 0;
}