n = int(input())
rope = []
for i in range(n):
    rope.append(int(input()))
rope.sort()
ret = 0
for i in range(1, n+1, 1):
    ret  = max(ret, rope[n-i]*i)
print(ret)