#include<iostream>
#include<vector>
#include<queue>
#include<map>


using namespace std;

struct info{
	int x;
	int y;
	int count;
};

int a,b,c,d;

void BFS() {
	queue< info > q;
	map< pair<int,int>, int> m;

	q.push({0,0});
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().count;
		q.pop();
		
		if(m.count({x,y}) > 0)
			continue;

		if (x == c && y == d) {
			cout << count;
			return;
		}

		m.insert({{x,y},1});

		if(x != a)
			q.push({a,y,count+1});
		if(y != b)
			q.push({x,b,count+1});
		if(x != 0)
			q.push({0,y,count+1});
		if(y != 0)
			q.push({x,0,count+1});
		if(x != 0 && y != b) {
			int diff = b-y;
			if (diff > x)
				q.push({0,y+x,count+1});
			else
				q.push({x-diff,b,count+1});
		}
		if(y != 0 && x != a) {
			int diff = a-x;
			if (diff > y)
				q.push({x+y, 0, count+1});
			else
				q.push({a,y-diff,count+1});
		}
	}

	cout << -1;

}

int main(void) {

	cin >> a >> b >> c >> d;

	BFS();
	return 0;
}