import sys
N, M = map(int, sys.stdin.readline().split())
arrN = sorted(list(map(int, sys.stdin.readline().split())))


def search(tree, last):
    print(tree, last)
    if len(tree) == M:
        print(*tree)
        return

    for i in range(last, N):
        print(i)
        if i != 0:
            if (arrN[i] == arrN[i - 1]):
                continue
        search(tree + [arrN[i]], i + 1)


search([], 0)
