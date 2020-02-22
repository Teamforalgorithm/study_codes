import sys

N, Q = map(int, sys.stdin.readline().split())
points = []
parent = list(range(N))
# distances = [[0] * N for _ in range(N)]
distances_x = dict([])
distances_y = dict([])


def find(x):
    if (x == parent[x]):
        return x
    else:
        y = find(parent[x])
        parent[x] = y
        return y


def union(x, y):
    x = find(x)
    y = find(y)
    parent[y] = x


for _ in range(N):
    points.append(tuple(map(int, sys.stdin.readline().split())))

for j in range(N):
    for i in range(N):
        if find(i) == find(j):
            continue
        elif (points[j][0] == points[i][0]) or (points[j][1] == points[i][1]):
            union(i, j)
            # else:
            #     distances[j][i] = distances[i][j] = \
            #         (points[i][0] - points[j][0]) ** 2 + \
            #         (points[i][1] - points[j][1]) ** 2

print()
for key, val in enumerate(parent):
    if not(val in distances_x):
        distances_x[val] = set([])
    if not(val in distances_y):
        distances_y[val] = set([])
    print(key, val)
    distances_x[val].add(points[key][0])
    distances_y[val].add(points[key][1])

# for i in distances_x:
#     print(''.join('{: 3d} '.format(j) for j in i))

print()
print(points)
print(parent)
print(distances_x)
print(distances_y)
print()

for i in range(Q):
    A, B, X = map(int, sys.stdin.readline().split())
    if find(A - 1) == find(B - 1):
        print("YES")
        continue
    else:
        x = y = 0
        # for j in range(Q):

        print(points[A - 1], points[B - 1])
