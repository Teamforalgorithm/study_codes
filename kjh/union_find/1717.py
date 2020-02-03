# WRONG
import sys

N, M = map(int, sys.stdin.readline().split())

parents = list(range(N + 1))


def getRoot(num):
    while parents[num] != num:
        num = parents[num]
    return num


for _ in range(M):
    method, a, b = map(int, sys.stdin.readline().split())
    if method == 0:
        parents[max(a, b)] = min(a, b)
    else:
        if getRoot(a) == getRoot(b):
            print("YES")
        else:
            print("NO")

# print(parents)
