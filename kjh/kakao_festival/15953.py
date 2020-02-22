import sys

T = int(sys.stdin.readline())
val_first = [0, 500, 300, 200, 50, 30, 10]
rank_first = [0] + [1] + [2] * 2 + [3] * 3 + \
    [4] * 4 + [5] * 5 + [6] * 6 + [0] * 79
# rank_first = [1, 3, 6, 10, 15, 21]
val_second = [0, 512, 256, 128, 64, 32]
rank_second = [0] + [1] + [2] * 2 + [3] * 4 + [4] * 8 + [5] * 16 + [0] * 69
# rank_second = [1, 3, 7, 15, 31]

# print(rank_first, rank_second)
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    print((val_first[rank_first[a]] + val_second[rank_second[b]]) * 10000)
