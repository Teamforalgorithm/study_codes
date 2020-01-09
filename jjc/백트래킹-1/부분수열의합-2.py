import sys
input=sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0

def solve(idx, sum):
  global ans
  if idx >= n:
    if sum == s:
      ans += 1
    return
  solve(idx+1, sum+arr[idx])
  solve(idx+1, sum)
  
solve(0, 0)
print(ans if s else ans-1)

