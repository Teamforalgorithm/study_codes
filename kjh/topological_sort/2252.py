import sys
from collections import deque
N, M = map(int, sys.stdin.readline().split())
parents = []
queue = deque([])
buffer = deque([])
[parents.append([]) for _ in range(N)]

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    parents[B - 1].append(A - 1)

while len(queue) < N:
    for key, val in enumerate(parents):
        if len(queue) == N:
            print(*queue, sep=' ')
            exit()
        if key in buffer:
            buffer.remove(key)
            queue.append(key + 1)

        if val == None:
            continue
        elif val == []:
            parents[key] = None
            buffer.append(key)
        else:
            for i in buffer:
                if i in val:
                    parents[key].remove(i)

# while True:
#     for i in range(N):
#         if parents[i] == []:
#             parents[i] = None
#             queue.append(i + 1)
#             for j in range(N):
#                 if (parents[j] != None) and (i in parents[j]):
#                     parents[j].remove(i)
#             # print(parents, queue)
#         if len(queue) == N:
#             print(*queue, sep=' ')
#             exit()

# print(parents)
# print(*queue, sep=' ')
# print("{}s seconds".format(time.time() - start_time))
