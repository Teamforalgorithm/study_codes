import sys

input = lambda: sys.stdin.readline().strip()
# 도시의 수
n = int(input())
# 계획에 속한 도시의 수
m = int(input())
parent = [0] * 201
rank = [0] * 201
#parent[a] = b :: a의 부모는 b다.
for i in range(1, n+1):
  parent[i] = i
  rank[i] = 1

# 두 부모를 합치는 함수
def union(parent, x, y):
  a = find(parent, x)
  b = find(parent, y)
  
  # 루트가 같으면 이미 같은 트리
  if x == y:
    return
  
  # x가 y보다 더 깊은 트리면 swap
  if rank[x] > rank[y]:
    x, y = y, x
  # x의 루트가 y가 되도록
  parent[x] = y
  # x와 y의 깊이가 같을 때, y의 깊이를 늘려준다.
  if rank[x] == rank[y]:
    rank[y]+=1

def find(parent, x):
  if parent[x] == x:
    # 루트 노드이면 return x
    return x
  # 아니면 자신의 루트를 찾는다.
  return find(parent, parent[x])

maps = []
for _ in range(n):
  maps.append(list(map(int, input().split())))


for i in range(n):
  for j in range(n):
    if j+1 > i+1 and maps[i][j] == 1:
      union(parent, i+1, j+1)


chk = True

plans = list(map(int, input().split()))
u = find(parent, plans[0])
for i in range(1, len(plans)):
  if u != find(parent, plans[i]):
    chk = False
    break

ans = chk is True and "YES" or "NO"
print(ans)


