#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, num = 0, value, sqrt_value;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> value;
        if (value < 2)
            continue;
        if (value == 2 || value == 3) {
            num++;
            continue;
        }
        sqrt_value = int(sqrt(value));
        
        for(int j = 2; j <= sqrt_value; j++) {
            if (value%j == 0)
                break;
            if (j == sqrt_value)
                num++;
        }
    }
    cout << num;
}
