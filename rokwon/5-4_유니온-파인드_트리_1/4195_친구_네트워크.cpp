#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int N, M;
int arr[2000001];
int num_balence[2000001];
int num_count[2000001];

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

        num_count[second] += num_count[first];
        num_count[first] = 1;
    }
    cout << num_count[second] << '\n';

}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    string str1;
    string str2;

    cin >> T;

    for(int t = 0; t < T; t++) {
        int count = 0;

        cin >> N;
        map<string, int> name;

        for(int i = 0; i < 2*N; i++) {
            arr[i] = i;
            num_balence[i] = 1;
            num_count[i] = 1;
        }

        for (int i = 0; i < N; i++) {
            cin >> str1;
            cin >> str2;

            if (name.count(str1) == 0) 
                name[str1] = count++;
            if (name.count(str2) == 0)
                name[str2] = count++;

            merge(name[str1], name[str2]);
        }
    }

    return 0;
}