# include <stdio.h>
# include <iostream>
# include <string.h>
# include <string>
# include <math.h>
# include <algorithm>
# include <stack>
# include <queue>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <functional>

# BAD CODE
using namespace std

int main()
{
    long long st, ed, a, b, v, mid, dap = 1000000001
    cin >> a >> b >> v

    st = 1
    ed = v

    while (st < ed)
    {
        mid = (st + ed) / 2
        if ((mid - 1) * (a - b) + a >= v)
        {
            ed = mid
            dap = min(dap, mid)
        }
        else
        {
            st = mid + 1
        }
    }
    cout << dap
}
