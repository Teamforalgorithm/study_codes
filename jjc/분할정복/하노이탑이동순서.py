import sys

input = lambda: sys.stdin.readline().strip()

'''
첫 번째 막대에서 세 번째 막대로 옮기는데 규칙
1. 한번에 한개의 원판만 다른 탑에 옮기는거 가능
2. 쌓인 원판은 항상 위의 것이 아래 것보다 작아야한다.

이동횟수가 최소가 되게끔 이동 과정을 출력

step 1) 작은 원반 n-1개를 A -> B로 옮기는 과정
step 2) 큰 원반 하나를 A -> C로 옮기는 과정
step 3) 작은 원반 n-1개를 B -> C로 옮기는 과정
'''

k = int(input())
cnt = 0
ans = []
def hanoi(x, start, mid, end):
  if x == 1:
    # step 1
    print(start, end)
  else:
    # step 2
    hanoi(x-1, start, end, mid)
    print(start, end)
    # step 3
    hanoi(x-1, mid, start, end)

for _ in range(k):
  cnt = cnt * 2
  cnt += 1

print(cnt)
hanoi(k, 1, 2, 3)

