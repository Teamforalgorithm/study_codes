#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001];
int counter;

int find(int i) {
    if (i == arr[i])
        return i;
    
    return arr[i] = find(arr[i]);
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int G, P;
    int num = 0;
    int check = 0;
    int point = 0;
    
    cin >> G >> P;

    for(int i = 1; i <= G; i++)
        arr[i] = i;

    for (int i = 1; i <= P; i++) {
        cin >> num;
        if (point == 0) {
            check = find(num);
            arr[check]--;

            if (arr[check] < 0)
                point = 1;  
            else
                counter++;
        }
        
    }

    cout << counter;

    return 0;
}