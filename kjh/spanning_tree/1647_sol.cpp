#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int p[100001];

struct edge
{
    int x, y, d;
    edge() : x(0), y(0), d(0) {}
    edge(int x, int y, int d) : x(x), y(y), d(d) {}
};

int Find(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    p[py] = px;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    vector<edge> e(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        e[i] = edge(x, y, d);
    }

    sort(e.begin(), e.end(), [](const edge &u, const edge &v) {
        return u.d < v.d;
    });

    int cost = 0;
    int maxv = -1;
    for (int i = 0; i < e.size(); i++)
    {
        int x = e[i].x;
        int y = e[i].y;
        int d = e[i].d;

        int px = Find(x);
        int py = Find(y);
        if (px != py)
        {
            cost += d;
            if (maxv == -1 || d > maxv)
            {
                maxv = d;
            }
            Union(x, y);
        }
    }

    cout << cost - maxv << '\n';
    return 0;
}