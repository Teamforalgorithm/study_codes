#include<iostream>
#include <vector>

using namespace std;

int T;
int n;
int num;

void plus_123(int sum) {
    if (sum > n)
        return;
    else if (sum == n) {
        num++;
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        plus_123(sum+i);
    }
}

int main(void) {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> n;
        plus_123(0);
        cout << num << '\n';
        num = 0;
    }
    
    return 0;
}


