#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int arr[1000001];
int num[1000001];

int find(int i) {
    
    if (i == arr[i])
        return i;
    
    return arr[i] = find(arr[i]);

}

void merge(int i, int j) {

    int first = find(i);
    int second = find(j);

    if (first != second){
        if(num[first] > num[second]) {
            swap(first, second);
        }

        arr[first] = second;
        if (num[first] == num[second] )
            ++num[second];
    }

}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int a, b, c;

    for(int i = 0; i <= N; i++) {
        arr[i] = i;
        num[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if(a == 0)
            merge(b,c);
        else {
            if (find(b) == find(c))
                cout << "YES" << '\n';
            else 
                cout << "NO" << '\n';
        }
    }

    return 0;
}