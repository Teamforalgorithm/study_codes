import sys

input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
m, v, c = [], [], []
arr = [] # jewelry
ans = 0
check = [False] * n
for _ in range(n):
  mi, vi = map(int, input().split())
  m.append(mi)
  v.append(vi)
  arr.append((mi, vi))

for _ in range(k):
  ci = int(input())
  c.append(ci)


for weight in c:
  idxList = [idx for idx, row in enumerate(arr) if row[0] <= weight ]
  acc = 0  
  for idx in idxList:
    if not check[idx]:
      acc = max(acc, v[idx])  
  check[v.index(acc)] = True
  ans += acc      

print(ans)