n, k = input().split()
n, k = int(n), int(k)

arr = []
for i in range(n):
    tmp = int(input())
    arr.append(tmp)

ret = 0
tmp = 0

for i in reversed(range(n)):
    tmp = int(k/arr[i])
    ret += tmp
    k -= (tmp * arr[i])
print(ret)
