import sys
N, M = map(int, sys.stdin.readline().split())


def search(tree, visited):

    if len(tree) == M:
        print(*tree)
        return

    for i in range(N):
        if not visited[i]:
            visited[i] = True
            search(tree + [i + 1], visited)
            visited[i] = False


search([], [False] * N)
