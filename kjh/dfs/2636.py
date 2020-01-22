# blank: 0 air: -1 cheeze: 1 meet-air: 2
import sys

N, M = map(int, sys.stdin.readline().split())
graph = []
time = 1
past_count = 0
hasAir = False
past_hasAir = False

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))

sys.setrecursionlimit(111111)


def meetAir(x, y):
    graph[y][x] = -1
    for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        if (y + dy < 0) or (y + dy >= N) or (x + dx < 0) or (x + dx >= M):
            continue

        val = graph[y + dy][x + dx]
        if val == 0:
            meetAir(x + dx, y + dy)
        elif val == 1:
            graph[y + dy][x + dx] = 2


def erode(x, y, time):
    global hasAir
    graph[y][x] = time
    for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        if (y + dy < 0) or (y + dy >= N) or (x + dx < 0) or (x + dx >= M):
            continue

        val = graph[y + dy][x + dx]
        if val == 0:
            hasAir = True
            erode(x + dx, y + dy, time)
        elif val == 1:
            graph[y + dy][x + dx] = time + 1


meetAir(0, 0)

# for i in range(N):
#     print(graph[i])
# print()

while True:
    time += 1
    count = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == time:
                count += 1
                erode(j, i, time)
    # print('count: ', count)
    if count == 0:
        # print(past_hasAir)
        if past_hasAir:
            past_count -= 1
        break
    else:
        past_count = count
        past_hasAir = hasAir
        hasAir = False

    # for i in range(N):
    #     print(graph[i])
    # print()

print(time - 2)
print(past_count)

# for i in range(N):
#     print(graph[i])
# print()
