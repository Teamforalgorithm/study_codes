import sys
input=sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0

def solve(idx, sum):
  global ans
  if idx >= n:
    # 처음에 헷갈렸는데 다 더한값이 S랑 같을 때니까 n이상
    if sum == s:
      ans += 1
    return
  solve(idx+1, sum+arr[idx])
  solve(idx+1, sum)
  
solve(0, 0)
#s가 0이면 아무것도 더하지 않은 공집합도 경우에 추가되므로 -1
print(ans if s else ans-1)

