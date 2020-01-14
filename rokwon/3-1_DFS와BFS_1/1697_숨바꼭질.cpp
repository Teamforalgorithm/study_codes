#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int arr[200002];
queue<int> que;
int N, K;

void BFS() {
    int num;
    que.push(N);
    while(arr[K] == 0) {
        for (int i = 0; i < 3; i++) {
            num = que.front();
            switch(i) {
                case 0:
                    if(arr[num + 1] == 0) {
                        arr[num + 1] = arr[num] + 1;
                        que.push(num+1);
                    }
                case 1:
                    if(num - 1 >= 0 && arr[num - 1] == 0 ) {
                        arr[num - 1] = arr[num] + 1;
                        que.push(num-1);
                    }
                case 2:
                    if(num * 2 <= 200000 && arr[num * 2] == 0) {
                        arr[num * 2] = arr[num] + 1;
                        que.push(num*2);
                    }
            }
        }
        que.pop();
    }
    

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    if(N == K) {
        cout << 0;
    }
    else if(K < N) {
        cout << N - K;
    }
    else {
        BFS();
        cout << arr[K];
    }

    

    

    return 0;
}

