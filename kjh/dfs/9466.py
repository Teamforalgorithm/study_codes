import sys
testcase = int(sys.stdin.readline())
count = 0

sys.setrecursionlimit(111111)


def search(arr, visited, seed, current):
    # current -= 1
    # print(visited, seed, current, visited[current], visited[arr[current] - 1])
    if visited[arr[current] - 1] == 1:
        if (seed == arr[current] - 1):
            visited[current] = 1
            return visited
        else:
            visited[seed] = 0
            return False
    visited[current] = 1
    search(arr, visited, seed, arr[current] - 1)


for i in range(testcase):
    count = 0
    N = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    visited = [0] * N
    for i in range(N):
        if visited[i] == 0:
            result = search(arr, visited, i, i)
            if type(result) == list:
                visited = result

    # print(visited)
    print(N - sum(visited))
