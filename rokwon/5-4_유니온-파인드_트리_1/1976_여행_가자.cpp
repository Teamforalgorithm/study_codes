#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int N, M;
int arr[201];
int num_balence[201];

int find(int i) {
    
    if (i == arr[i])
        return i;
    
    return arr[i] = find(arr[i]);

}

void merge(int i, int j) {

    int first = find(i);
    int second = find(j);

    if (first != second){
        if(num_balence[first] > num_balence[second])
            swap(first, second);

        arr[first] = second;

        if (num_balence[first] == num_balence[second] )
            ++num_balence[second];
        
    }

}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int num = 0;

    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        arr[i] = i;
        num_balence[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> num;
            if (num == 1) {
                merge(i,j);
            }
        }
    }

    bool same = true;
    cin >> num;
    int first_city = find(num);

    for (int i = 1; i < M; i++) {
        cin >> num;
        if (first_city != find(num)) {
            same = false;
        }
    }

    if (same)
        cout << "YES";
    else
        cout << "NO";




    return 0;
}