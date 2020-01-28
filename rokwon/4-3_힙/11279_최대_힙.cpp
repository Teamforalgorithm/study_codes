#include<iostream>
#include<vector>
#include<queue>
#include<functional>
 
using namespace std;
 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 0;
    priority_queue< int,vector<int>,less<int> > heap;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num != 0)  {
            heap.push(num);
        }
        else {
            if(heap.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
        
    }
    
    return 0;
}