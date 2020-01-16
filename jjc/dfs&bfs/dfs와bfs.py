import sys
input = sys.stdin.readline

n, m, start = map(int, input().split())

maps = [[0]*(n+1) for i in range(n+1)]

for i in range(m):
  x, y = map(int, input().split())
  maps[x][y] = 1
  maps[y][x] = 1


def dfs(current_node, row, visited):
  visited += [current_node]
  for search_node in range(len(row[current_node])):
    if row[current_node][search_node] and search_node not in visited:
      visited = dfs(search_node, row, visited)

  return visited

def bfs(start):
  que = [start]
  visited = [start]

  while(que):
    current_node = que.pop(0)
    for search_node in range(1, len(maps[current_node]), 1):
      if maps[current_node][search_node] and search_node not in visited:
        visited += [search_node]
        que += [search_node]

  return visited

print(*dfs(start, maps, []))
print(*bfs(start))