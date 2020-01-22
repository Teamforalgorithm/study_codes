import sys
input = lambda: sys.stdin.readline().strip()

n = input()
cnt0 = 0 # 모두 0으로 바꾸는 경우
cnt1 = 0 # 모두 1로 바꾸는 경우

if n[0] == '1':
  cnt0 += 1
else:
  cnt1 += 1

for i in range(len(n)-1):
  if n[i] != n[i+1]:
    if n[i+1] == '1':
      cnt0 += 1
    else:
      cnt1 += 1

print(min(cnt0, cnt1))



