# import sys
# from collections import deque

# N, L = map(int, sys.stdin.readline().split())
# sizeL = (2 * L) + 1
# arr = []
# count = 0


# def checkTile(kernel):
#     low = min(kernel)
#     high = max(kernel)
#     points = []
#     for i in range(sizeL):
#         if kernel[i] == high:
#             points.append(i)

#     print("points: ", points)

#     if high == low:
#         return True
#     if high - low > 1:
#         return False

#     for a, b in zip(points[:-1], points[1:]):
#         if (b - a) > 1 and (b - a) < sizeL:
#             return False
#     return True


# for _ in range(N):
#     arr.append(list(map(int, sys.stdin.readline().split())))

# for j in range(N):
#     kernel = deque([0] + arr[j][:sizeL - 1])
#     print("*kernel: ", kernel)
#     for i in range(sizeL - 1, N):
#         kernel.popleft()
#         kernel.append(arr[j][i])
#         print("kernel: ", kernel, end='  ')

#         if checkTile(kernel):
#             print('TRUE')
#             continue
#         else:  # if fail
#             print('FALSE')
#             count += 1
#             break

# for j in range(N):
#     kernel = deque([0] + arr[j][:sizeL - 1])
#     print("*kernel: ", kernel)
#     for i in range(sizeL - 1, N):
#         kernel.popleft()
#         kernel.append(arr[j][i])
#         print("kernel: ", kernel, end='  ')

#         if checkTile(kernel):
#             print('TRUE')
#             continue
#         else:  # if fail
#             print('FALSE')
#             count += 1
#             break

# print(count)


import sys
N, A, B = map(int, sys.stdin.readline().split())
S = sys.stdin.readline()

print(S, end='')
