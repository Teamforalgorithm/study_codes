import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
parent = [0]*1000001

# 처음에는 각 원소들에 연결된 정보가 없어서 부모로 자기 자신을 가지고 있다.
# 즉 자기 자신이 부모임
for i in range(n):
  parent[i] = i

def Find(x):
  global parent
  if x == parent[x]:
    return x
  else:
    y = Find(parent[x])
    parent[x] = y
    return y


def Union(x, y):
  global parent
  x = Find(x)
  y = Find(y)
  parent[y] = x

'''
합집합은 0 a b의 형태 => a와 b를 합치는 연산
1 a b의 형태 => 두 원소가 같은 집합에 포함되어 있는지에 대한 연산
1 a b의 연산에 대해서만 YES/NO로 출력한다.
'''

for _ in range(m):
  op, a, b = map(int, input().split())
  if op == 0:
    Union(a, b)
  elif op == 1:
    ap = Find(a)
    bp = Find(b)
    
    if ap == bp:
      print('YES')
    else:
      print('NO')


