import sys

N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

arr = list(reversed(sorted(arr)))

# print(arr)

acquired = 0
count = 1
identical = 1

for i, j in zip(arr, arr[1:] + [0]):
    if (i - j) == 0:
        identical += 1
        count += 1
        continue

    acquired += (i - j) * count
    # print(acquired)

    if acquired >= M:
        if identical > 1:
            # print(identical)
            # print('j: ', j)
            # print('acquired_sum: ', ((acquired - M) // (identical + 1)))
            print(j + ((acquired - M) // (identical + 1)))
        else:
            print(j)
        break
    identical = 1
    count += 1
