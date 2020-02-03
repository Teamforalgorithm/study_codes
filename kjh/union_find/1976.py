import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
mat = []
plan = []
parents = list(range(N))

for _ in range(N):
    mat.append('0b'+''.join(list(map(str, sys.stdin.readline().split()))))

plan = list(map(int, sys.stdin.readline().split()))

print(mat)
# print(1 in mat[1])
# print(mat[1].index(2))
# for i in range(N):
#     if 
