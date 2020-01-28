#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<utility>
#include<set>
 
using namespace std;

bool compare(const pair<int,int>& i, const pair<int,int>& j) {
    return i.second > j.second;
}
 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int first = 0, second = 0;
    int max_value = 0;
    long long sum = 0;
    int value = 0;

    cin >> N >> K;

    vector<pair<int,int>> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> first >> second;
        arr[i] = pair<int, int>(first,second);
    }
    sort(arr.begin(), arr.end(), compare);


    multiset<int> bag;

    for(int i = 0; i < K; i++) {
        cin >> value;
        bag.insert(value);
    }

    multiset<int>::iterator iter;

    for (int i = 0; i < N; i++) {
        iter = bag.lower_bound(arr[i].first);

        if ( *iter >= arr[i].first && !bag.empty() && iter != bag.end() ) {
            sum += arr[i].second;
            bag.erase(iter);
        }
    }

    cout << sum;


    
    
    return 0;
}