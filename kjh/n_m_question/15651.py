import sys
N, M = map(int, sys.stdin.readline().split())


def search(tree, last):
    if len(tree) == M:
        print(*tree)
        return

    for i in range(N):
        search(tree + [i + 1], i + 1)


search([], 0)
