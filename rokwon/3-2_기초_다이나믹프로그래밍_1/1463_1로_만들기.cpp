#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.ite(NULL);
    
  int N;

  cin >> N;

  vector<int> v(N+1);
    
  if (N>=2)
    v[2] = 1;
    
  int count = 0;
  vector<int> min_val;

  for(int i = 3; i <= N; i++) {
    count = 0;

    if(i%2==0)
      min_val.push_back(v[i/2]);
    if(i%3==0)
      min_val.push_back(v[i/3]);
    min_val.push_back(v[i-1]);

    v[i] = *min_element(min_val.begin(), min_val.end())+1;

	  min_val.clear();
  }

  cout << v[N];

  return 0;
}
