import sys

V, E = map(int, sys.stdin.readline().split())
# graph = []
# [graph.append([0] * V) for _ in range(V)]

info = []

for _ in range(E):
    [i, j, value] = map(int, sys.stdin.readline().split())
    info.append([i - 1, j - 1, value])
    # i, j, value = map(int, sys.stdin.readline().split())
    # graph[i - 1][j - 1] = value


# print(graph, info)


class DisjointSet:
    def __init__(self, n):
        self.parent = {}
        self.rank = {}
        for i in range(n):
            self.parent[i] = i
            self.rank[i] = 0

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def union(self, root1, root2):
        if self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root1] = root2
            if self.rank[root1] == self.rank[root2]:
                self.rank[root2] += 1


def kruskal(n, info):
    min_weight = 0
    disjoint_set = DisjointSet(n)
    # result = []
    for data in sorted(info, key=lambda cost: cost[2]):
        v, u, weight = data
        root1 = disjoint_set.find(v)
        root2 = disjoint_set.find(u)
        if root1 != root2:
            disjoint_set.union(root1, root2)
            # result.append(data)
            min_weight += data[2]

    return min_weight
    # return result, min_weight


print(kruskal(E, info))
