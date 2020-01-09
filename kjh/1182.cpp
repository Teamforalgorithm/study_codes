#include <iostream>
#include <vector>

using namespace std;

#define N 0
#define S 1
#define RESULT 2

void dfs(vector<int> _num_lists, vector<int> *_arr, int length, int sum, int cnt)
{
    if (cnt == _arr->at(N))
    {
        // 주어진 s와 sum이 같고, length가 0이 아닌경우(= 뭐라도 하나의 값은 합한경우)
        if (sum == _arr->at(S) && length > 0)
        {
            _arr->at(RESULT)++;
        }
        return;
    }

    // _num_lists[cnt]에 해당하는 숫자를 더하는 경우
    dfs(_num_lists, _arr, length + 1, sum + _num_lists.at(cnt), cnt + 1);

    // _num_lists[cnt]에 해당하는 숫자를 더하지 않는경우
    dfs(_num_lists, _arr, length, sum, cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> num_lists;
    vector<int> arr(3);

    /* 입력단 */
    cin >> arr.at(N) >> arr.at(S);
    num_lists.resize(arr.at(N));
    for (int i = 0; i < arr.at(N); i++)
    {
        cin >> num_lists.at(i);
    }

    /* DFS*/
    dfs(num_lists, &arr, 0, 0, 0);

    /* 출력단 */
    cout << arr.at(RESULT) << "\n";

    return 0;
}
