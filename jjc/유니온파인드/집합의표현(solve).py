import sys
input = sys.stdin.readline
print = sys.stdout.write

def Find(x):
  while x != parent[x]:
    x = parent[x]
  return parent[x]

def Union(x, y):
  x = Find(x)
  y = Find(y)
  
  if x == y:
    return
  if rank[x] < rank[y]:
    parent[x] = y
  else:
    parent[y] = x
  if rank[x] == rank[y]:
    rank[x] += 1

def is_same(x, y):
  return "YES\n" if Find(x) == Find(y) else "NO\n"

n, m = map(int, input().split())
parent = [i for i in range(n+1)]
rank = [0]*(n+1)
i = 0
while i < m:
  op, a, b = map(int, input().split())
  if op:
    print(is_same(a, b))
  else: 
    Union(a, b)
  i += 1