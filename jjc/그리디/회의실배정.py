n = int(input())
arr = []
for i in range(n):
    line = list(map(int, input().split()))
    arr.append(line)

arr = sorted(arr, key=lambda arr: arr[0])
arr = sorted(arr, key=lambda arr: arr[1])


ret = 0
curtime = 0
# for i in range(n):
#     if(curtime <= arr[i][0]):
#         ret += 1
#         curtime = arr[i][1]
#     else:
#         continue

for time in arr:
    if time[0] >= curtime:
        curtime = time[1]
        ret += 1

print(ret)
