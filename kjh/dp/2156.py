import sys

num = int(sys.stdin.readline())
arr = []
dp = [0] * num

for i in range(num):
    arr.append(int(sys.stdin.readline()))

dp[0] = arr[0]
if num > 1:
    dp[1] = arr[1] + arr[0]

if num > 2:
    for n in range(2, num):
        dp[n] = max(max(arr[n] + dp[n - 2], dp[n - 1]),
                    arr[n] + arr[n - 1] + dp[n - 3])

print(dp[num - 1])
