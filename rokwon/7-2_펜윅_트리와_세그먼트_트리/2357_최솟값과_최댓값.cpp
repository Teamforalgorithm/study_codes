#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> segment_tree[400001];
pair<int, int> arr[400001];

pair<int, int> make_segment(int index, int start, int end) {

	if (start == end)
		segment_tree[index] = arr[start];
	else {
		pair<int, int> p1, p2;
		p1 = make_segment(index*2+1, start, (start+end)/2);
		p2 = make_segment(index*2+2, (start+end)/2+1, end);
		segment_tree[index] = { min(p1.first, p2.first), max(p1.second, p2.second) };
	}

	return segment_tree[index];
}

pair<int, int> part_pair(int i, int start, int end, int left, int right) {

	if ( left > end || right < start)
		return {2100000000, 0};
	else if (left <= start && right >= end)
		return segment_tree[i];
	else {
		pair<int, int> p1, p2;
		p1 = part_pair(i*2+1,start,(start+end)/2, left, right);
		p2 = part_pair(i*2+2,(start+end)/2+1, end, left, right);
		return  {min(p1.first, p2.first), max(p1.second, p2.second)};
	}
		
}



int main() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a,b;

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = arr[i].first;
	}
	make_segment(0, 0, N-1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		pair<int, int> ans = part_pair(0, 0, N-1, a-1, b-1);

		cout << ans.first << ' ' << ans.second << '\n';
	}

	
	return 0;
}