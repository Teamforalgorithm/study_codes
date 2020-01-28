#include <iostream>

using namespace std;

int N; //주어진 정수

int cache[11]; //N<11

//풀어보면 점화식은 f(x)=f(x-1)+f(x-2)+f(x-3)

int method(void)

{

    cache[1] = 1; //1

    cache[2] = 2; //1+1, 2

    cache[3] = 4; //1+1+1, 1+2, 2+1, 3

    for (int i = 4; i <= N; i++)

        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];

    return cache[N];
}

int main(void)

{

    int test_case;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)

    {

        cin >> N;

        cout << method() << endl;
    }

    return 0;
}