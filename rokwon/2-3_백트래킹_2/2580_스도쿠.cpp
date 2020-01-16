#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector< pair<int, int> > arr;
int sdoku[9][9];

bool row(int x, int i) {
    for(int z = 0; z < 9; z++) {
        if (sdoku[x][z] == i)
            return false;
    }
    return true;
}

bool col(int y, int i) {
    for(int z = 0; z < 9; z++) {
        if (sdoku[z][y] == i)
            return false;
    }
    return true;
}
bool squ(int x, int y, int i) {

    int a, b;
    if(x < 3) a = 0;
    else if (x < 6) a = 3;
    else a = 6;

    if(y < 3) b = 0;
    else if (y < 6) b = 3;
    else b = 6;

    for (int a1 = a;  a1 < a+3; a1++) {
        for (int b1 = b; b1 < b+3; b1++) {
            if (sdoku[a1][b1] == i)
                return false;
        }
    }
    return true;
}

void DFS(int count) {
    if (count == arr.size()) {
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sdoku[i][j] << " ";
            cout << '\n';
        }
        exit(0);
    }

    for(int i = 1; i <= 9; i++) {
        if(row(arr[count].first, i) && col(arr[count].second, i) && squ(arr[count].first, arr[count].second, i)) {
            sdoku[arr[count].first][arr[count].second] = i;
            DFS(count + 1);
            sdoku[arr[count].first][arr[count].second] = 0;
        }
    }

}

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0){
                arr.push_back( pair<int,int>(i,j) );
            }
        }
    }

    DFS(0);

    return 0;
}