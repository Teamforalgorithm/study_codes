#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
 
using namespace std;

bool cmp(const pair<int,int>& p, const pair<int,int>& q)
{
	if(p.second != q.second)
		return p.second < q.second;
	return p.first < q.first;
}

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int N, M;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N >> M;
        pair<int, int> arr[M];
        int first = 0, second = 0;

        for (int j = 0; j < M; j++) {
            cin >> first >> second;
            arr[j] = pair<int, int>(first, second);
        }

        sort(arr, arr+M, cmp);

        int book = 0;
        bool check[1001] = {false, };


        for (int j = 0; j < M; j++) {
            for(int z = arr[j].first; z <= arr[j].second; z++) {
                if( check[z] == false ) {
                    check[z] = true;
                    book++;
                    break;
                }
            }

        }
        
        cout << book << '\n';

    }

    return 0;
}