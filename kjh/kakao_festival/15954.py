import sys
import math
from collections import deque

N, K = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

# queue = deque(arr[0:K])
min_dispersion = 1000000
min_k = 500

for k in range(K, N + 1):
    queue = deque(arr[0:k])
    for i in (arr[k:] + [0]):
        mean = sum(queue) / k
        dispersion_times_N = 0
        for j in queue:
            dispersion_times_N += (j - mean) ** 2
        # print(queue, mean, dispersion_times_N / k)
        if dispersion_times_N < min_dispersion:
            min_dispersion = dispersion_times_N
            min_k = k
        queue.popleft()
        queue.append(i)

print(math.sqrt(min_dispersion / min_k))
