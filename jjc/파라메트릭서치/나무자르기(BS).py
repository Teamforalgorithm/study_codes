import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
tree = list(map(int, input().split()))

def treeSum(height):
  sum = 0
  for i in tree:
    if i-height > 0:
      sum += (i-height)

  return sum

def BSearch(target):
  start,end = 0, max(tree)
  ans = 0
  while(start <= end):
    mid = (start + end) // 2
    sum = treeSum(mid)
    if sum < target:
      end = mid-1
    if sum >= target:
      ans = mid
      start = mid+1
  return ans

print(BSearch(m))