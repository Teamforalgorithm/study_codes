import sys
N, M = map(int, sys.stdin.readline().split())
arrN = sorted(list(map(int, sys.stdin.readline().split())))


def search(tree, visited):
    if len(tree) == M:
        print(*tree)
        return

    for i in range(N):
        if not visited[i]:
            visited[i] = True
            search(tree + [arrN[i]], visited)
            visited[i] = False


search([], [False] * N)
