import sys
sys.stdin = open("input.txt", 'r')

import collections


def heavier_bfs(v):
    q = collections.deque()
    q.append(v)
    visited = [False for _ in range(N + 1)]
    visited[v] = True

    while q:
        v = q.popleft()
        for e in heavier_adj[v]:
            if not visited[e]:
                visited[e] = True
                q.append(e)
    return visited


def lighter_bfs(v):
    q = collections.deque()
    q.append(v)
    visited = [False for _ in range(N + 1)]
    visited[v] = True

    while q:
        v = q.popleft()
        for e in lighter_adj[v]:
            if not visited[e]:
                visited[e] = True
                q.append(e)
    return visited


N = int(input())
M = int(input())
heavier_adj = [[] for _ in range(N + 1)]
lighter_adj = [[] for _ in range(N + 1)]

for i in range(M):
    a, b = map(int, input().split())
    heavier_adj[b].append(a)
    lighter_adj[a].append(b)

for v in range(1, N + 1):
    compare = [False for _ in range(N + 1)]
    for i, state in enumerate(heavier_bfs(v)[1:], 1):
        if state:
            compare[i] = True

    for i, state in enumerate(lighter_bfs(v)[1:], 1):
        if state:
            compare[i] = True
    print(compare[1:].count(False))
