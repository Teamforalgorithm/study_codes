#include<iostream>

using namespace std;

int a(int q, int w) {
	int r;
	while (q % w != 0) {
		r = w;
		w = q % w;
		q = r;
	}
	cout << w << '\n';
	return w;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;
	int w = 0;

	if (N < M) {
		w = a(M, N);
		cout << (M / w) * N;
	}
	else {
		w = a(N, M);
		cout << (N / w) * M;
	}



	return 0;
}
