def slope(i, c):
    global ans
    cnt = 1
    for j in range(0, N - 1):
        d = a[i][j + 1] - a[i][j] if c else a[j + 1][i] - a[j][i]
        if d == 0:
            cnt += 1
        elif d == 1 and cnt >= L:
            cnt = 1
        elif d == -1 and cnt >= 0:
            cnt = -L + 1
        else:
            return
    if cnt >= 0:
        ans += 1


def solve():
    for i in range(N):
        slope(i, 1)
        slope(i, 0)
    print(ans)


N, L = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(N)]
ans = 0
solve()
