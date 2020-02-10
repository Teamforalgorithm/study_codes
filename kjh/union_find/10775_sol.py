import sys
sys.setrecursionlimit(9999999)
G = int(input())
P = int(input())

root = []

for i in range(G + 1):
    root += [i]


def find(n):
    if n == root[n]:
        return n
    root[n] = find(root[n])
    return root[n]


list = []

for i in range(P):
    list += [int(input())]

ans = 0

for p in list:
    r = find(p)
    if r == 0:
        break
    root[r] = r - 1
    ans += 1

print(ans)
