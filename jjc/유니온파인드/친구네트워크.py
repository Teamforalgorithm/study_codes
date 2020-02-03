import sys

input = lambda: sys.stdin.readline().strip()

# 이름이 노드, 친구 관계가 간선

def getParent(parents, x):
  if parents[x] == x:
    return x
  # path compression
  p = getParent(parents, parents[x])
  parents[x] = p
  return p

# 두 부모를 합치는 함수
def union(parents, x, y, cnt):
  a = getParent(parents, x)
  b = getParent(parents, y)
  if a!=b:
  parents[b] = a
  cnt[a] += cnt[b]

# 루트 찾기
def find(x, parents):
  if parents[x] == x:
    return x
  return find(parents[x], parents)


for _ in range(int(input())):
  parents = {}
  cnt = {}
  for _ in range(int(input())):
  fr1, fr2 = input().split()

  if fr1 not in parents:
    parents[fr1] = fr1
    cnt[fr1] = 1
  
  if fr2 not in parents:
    parents[fr2] = fr2
    cnt[fr2] = 1

  union(parents, fr1, fr2, cnt)
  print(cnt[find(fr1, parents)])



