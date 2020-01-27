#include<iostream>
#include<vector>
#include<queue>
#include<functional>
 
using namespace std;
 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0, num = 0;
    int first = 0, second = 0;

    priority_queue< int,vector<int>, greater<int> > heap;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        heap.push(num);
    }

    while ( heap.size() != 1 ) {
        first = heap.top();
        heap.pop();
        second = heap.top();
        heap.pop();
        sum += first+second;
        heap.push(first+second);
    }

    if ( N == 1) {
        cout << 0;
    }else {
        cout << sum;
    }
    
    return 0;
}