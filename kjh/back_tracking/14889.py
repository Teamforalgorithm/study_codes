import sys

N = int(sys.stdin.readline().split()[0])
M = N // 2
graph = []
orders = []
values = []
min_score = 1000

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))


def combination(a, b, tree, last, target):
    if len(tree) == b:
        target.append(tree)
        return

    # print(last, a)
    for i in range(last, a):
        combination(a, b, tree + [i], i + 1, target)


combination(N, M, [], 0, orders)
# print(orders)

combination(M, 2, [], 0, values)

for i in orders[:len(orders)//2]:
    score = 0
    j = list(set(range(N)) ^ set(i))
    # print(i, j)
    for v in values:
        score += graph[i[v[0]]][i[v[1]]] + graph[i[v[1]]][i[v[0]]]
        score -= graph[j[v[0]]][j[v[1]]] + graph[j[v[1]]][j[v[0]]]
    if abs(score) < min_score:
        min_score = abs(score)

print(min_score)

