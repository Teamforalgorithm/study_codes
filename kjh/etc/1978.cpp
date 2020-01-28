#include <iostream>

#include <cmath>

using namespace std;

const int MAX = 100;

int minFactor[1001]; //minFactor[i] -> i의 가장 작은 소인수(i가 소수인 경우 자기 자신)

//에라토스테네스의 체

void eratosthenes(void)

{

    //1은 항상 예외

    minFactor[0] = minFactor[1] = -1;

    //모든 숫자를 처음에는 소수로 표시

    for (int i = 2; i <= 1001; i++) //수가 최대 1000이므로

        minFactor[i] = i;

    //에라토스테네스의 체 수행

    int sqrtN = int(sqrt(1001)); //루트 N

    for (int i = 2; i <= sqrtN; i++)

        if (minFactor[i] == i)

            for (int j = i * i; j <= 1001; j += i)

                //아직 약수를 본적 없는 숫자인 경우 i를 써둔다

                if (minFactor[j] == j)

                    minFactor[j] = i;
}

int main(void)

{

    int N;

    cin >> N;

    int cnt = 0;

    eratosthenes();

    //N개의 숫자

    for (int i = 0; i < N; i++)

    {

        int num;

        cin >> num;

        if (minFactor[num] == num) //소수이면 추가

            cnt++;
    }

    cout << cnt << endl;

    return 0;
}