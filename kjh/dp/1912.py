import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

c = d = arr[0]
result = -1000

for i in arr[1:]:
    d = max(d + i, i)
    result = max(result, d)

result = max(result, arr[0])

print(result)

# val_total = 0
# val_temp = 0
# val_min = 0
# val_result = arr[0]

# for i in arr:
#     val_total += i
#     val_temp += i

#     if val_temp < 0:
#         val_min += val_temp
#         val_temp = 0
    
#     if val_result < (val_total - val_min):
#         val_result = val_total - val_min

#     print("%4d %4d %4d %4d %4d" % (i, val_min, val_temp, val_total, val_result))

# print(val_result)

