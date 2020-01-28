import sys

N, C = map(int, sys.stdin.readline())
arr = []
points = []

for i in range(N):
    arr.append(int(sys.stdin.readline()))

arr.sort()


def binarySearch(start, end, distance){
    mid = (start + end) / 2
    val = end
    for i, j in zip(arr, arr[1:] + [0]):
        if j > mid:
            val = min(abs(j - mid), abs(mid - i))
            break

    if val < distance:
        return val

    return val

    max_distance = binarySearch(start, val, distance)
    max_distance =
}


start, end = arr[0], arr[-1]
binarySearch(start, end, start - end)
