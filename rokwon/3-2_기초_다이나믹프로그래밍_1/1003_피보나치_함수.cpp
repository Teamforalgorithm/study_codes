
#include<iostream>
#include<vector>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    vector<int> v0(41);
    vector<int> v1(41);
    v0[0] = 1;
    v1[1] = 1;

    for(int i = 2; i <= 40; i++) {
        v0[i] = v0[i-1] + v0[i-2];
        v1[i] = v1[i-1] + v1[i-2];
    }

    int num;

    for(int i = 0; i < T; i++){
        cin >> num;
        cout << v0[num]<<" "<<v1[num]<< '\n';
    }
    return 0;
}
