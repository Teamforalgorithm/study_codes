#include<iostream>
#include<vector>

using namespace std;

vector<int> full_arr(6);

void PrintLotto(vector<int> arr, int index, int end) {
    if (end == 6) {
        for (int i = 0; i < 6; i++)
            cout << full_arr[i] << " ";
        cout << '\n';
        return;
    }
    
    for (int i = index; i < arr.size(); i++) {
        full_arr[end] = arr[i];
        PrintLotto(arr, i+1, end+1);
    }
}

int main(void) {
    
    while(true) {
        int N;
        
        cin >> N;
        
        if(N == 0)
            break;
        
        vector<int> arr(N, 0);
        
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        PrintLotto(arr,0,0);
        cout << '\n';
    }
    return 0;
}
