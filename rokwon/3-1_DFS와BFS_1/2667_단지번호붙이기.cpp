#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N;
int arr[27][27];
int visit_arr[27][27];
vector<int> house_num;
int num;

void DFS(int i, int j) {
    if(visit_arr[i][j] == 1) {
        return;
    }
    else if(arr[i][j] == 0){
        visit_arr[i][j] = 1;
        return;
    }
    else {
        visit_arr[i][j] = 1;
        num += 1;
        DFS(i-1,j);
        DFS(i+1,j);
        DFS(i,j-1);
        DFS(i,j+1);
    }

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "";
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j+1] = str[j] - '0';
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DFS(i, j);
            if(num > 0) {
                house_num.push_back(num);
            }
            num = 0;
        }
    }

    sort(house_num.begin(), house_num.end());

    cout << house_num.size() << '\n';

    for(int i = 0; i < house_num.size(); i++) {
        cout << house_num[i] << '\n';
    }

    return 0;
}

