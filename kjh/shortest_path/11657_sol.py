import sys
n, m = map(int, sys.stdin.readline().split())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
bf = [1e9] * (n + 1)


def solve_bf():
    bf[1] = 0
    minus = False
    for i in range(n):
        for j in range(m):
            v = graph[j][0]
            nv = graph[j][1]
            w = graph[j][2]
            if bf[v] != 1e9 and bf[nv] > bf[v] + w:
                bf[nv] = bf[v] + w
                if i == n - 1:
                    minus = True
    if minus:
        print(-1)
    else:
        for i in range(2, n + 1):
            if bf[i] == 1e9:
                print(-1)
            else:
                print(bf[i])


solve_bf()
