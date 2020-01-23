#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<bool> isPrime(N + 1, true);
    bool chk = false;

    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = M; i <= N; i++)
        if (isPrime[i])
            cout << i << '\n';

    return 0;
}
