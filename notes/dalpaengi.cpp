// 굳이 이분탐색법으로 안 풀어도 되지만 이분탐색법 분류에 들어가 있는 문제였기 때문에 BinarySearch를 이용하여 풀었습니다.
// 달팽이는 하루에(A - B) 만큼 움직이고 마지막날에는 A만큼 올라가서 목표지점에 도달하거나 초과합니다.
// 따라서 결과는 totalDay(mid) 가 아닌 totalDay
// + 1이여야 합니다.
//   그리고 한가지 주의할 점은 INF를 1,
// 000, 000, 000 이상으로 설정해야한다는 점입니다.(1 ≤ B < A ≤ V ≤ 1, 000, 000, 000)

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1000000000 + 1;
int A, B, V;
long long binarySearch(void)
{
    long long left = 0, right = V / (A - B) + 1;
    long long totalDay;
    long long result = INF;

    while (left <= right)
    {
        totalDay = (left + right) / 2;
        //하루 움직이는 거리: (올라가는 길이 - 미끄러지는 길이)
        //마지막 날에는 올라가기만 한다
        if (V <= totalDay * (A - B) + A)
        {
            //마지막 날까지 고려하므로 totalDay + 1
            result = min(result, totalDay + 1);
            right = totalDay - 1;
        }

        else
            left = totalDay + 1;
    }

    return result;
}

int main(void)

{
    cin >> A >> B >> V;
    cout << binarySearch() << endl;
    return 0;
}