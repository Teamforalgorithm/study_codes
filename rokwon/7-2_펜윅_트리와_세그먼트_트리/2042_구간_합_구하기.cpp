#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
long long segment_tree[4000001];
long long arr[4000001];

long long make_segment(int index, int start, int end) {

	if (start == end)
		segment_tree[index] = arr[start];
	else
		segment_tree[index] = make_segment(index*2+1, start, (start+end)/2) + make_segment(index*2+2, (start+end)/2+1, end);

	return segment_tree[index];
}

long long part_sum(int i, int start, int end, int left, int right) {

	if ( left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return segment_tree[i];
	else
		return part_sum(i*2+1,start,(start+end)/2, left, right) + part_sum(i*2+2,(start+end)/2+1, end, left, right);
}

void update_value(int change_i, long long diff, int i ,int start, int end) {
	if (change_i < start || change_i > end)
		return;
	
	segment_tree[i] += diff;

	if (start != end) {
		update_value(change_i, diff, i*2+1, start, (start+end)/2 );
		update_value(change_i, diff, i*2+2, (start+end)/2+1, end );

	}
}



int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a,b,c;

	cin >> N >> M >> K;

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	make_segment(0, 0, N-1);

	for(int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update_value(b-1, c - arr[b-1], 0, 0, N-1);
			arr[b-1] = c;
		}
		else
			cout << part_sum(0, 0, N-1, b-1, c-1) << '\n';
	}


	
	

	

	return 0;
}