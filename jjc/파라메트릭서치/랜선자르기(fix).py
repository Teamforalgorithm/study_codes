import sys
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
arr.sort(reverse = True)

def BSearch(target):
  start, end = 1, max(arr)
  ans = 0

  while(start <= end):
    mid = (start + end) // 2
    sum_cnt = sum([(i // mid) for i in arr])
    if sum_cnt == 0:
      return 1

    if sum_cnt < target:
      end = mid - 1
    elif sum_cnt >= target:
      ans = mid
      start = mid + 1
    
  return ans

print(BSearch(k))