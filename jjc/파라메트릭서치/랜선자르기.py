import sys
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
arr.sort(reverse = True)

def check(num):
  ret = 0
  for i in arr:
    ret += (i // num)
  return ret

def BSearch(target):
  # start가 0에서 시작하면 런타임 에러
  # 1로 바꿔야한다.
  start, end = 0, max(arr)
  ans = 0
  while(start <= end):
    mid = (start + end) // 2
    sum = check(mid)
    if sum == 0:
      return 1
    if sum < target:
      end = mid-1
    if sum >= target:
      ans = mid
      start = mid+1
  return ans

print(BSearch(k))