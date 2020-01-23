import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr2 = sorted(list(set(arr)))
largest = 0

# print(arr, arr2)

# for j in range(N):
#     for i in range(j, len(arr2)):
#         print(i, j, arr2[i], arr[j])
#         if arr[j] == arr2[i]:
#             count += 1
#             break

for k in range(len(arr2)):
    count = 0
    for i in arr2[k:]:
        j = 0
        while j < N:
            print(arr2[k], i, arr[j])
            if arr[j] == i:
                # print('above')
                count += 1
                j += 1
                break
            j += 1
    if count > largest:
        largest = count

# for k in range(len(arr2)):
#     count = 0
#     j = k
#     for i in range(k, len(arr2)):
#         while j < N:
#             print(arr[k], i, j, arr2[i], arr[j])
#             if arr[j] == arr2[i]:
#                 print('above')
#                 count += 1
#                 j += 1
#                 break
#             j += 1
#     if count > largest:
#         largest = count

        # for i in range(len(arr2)):
        #     for j in range(i, N):
        #         print(i, j, arr2[i], arr[j])
        #         if arr2[i] == arr[j]:
        #             count += 1
        #             break

print(largest)
