import sys
input = lambda: sys.stdin.readline().strip()

# (n=0) => (1, 0) , (n=1) => (0, 1), (n=3) => (1, 2)

def fibo(n):
  zero = [1, 0, 1]
  one = [0, 1, 1]
  if n<= 1:
    return

  for i in range(3, n+1):
    zero.append(zero[i-1] + zero[i-2])
    one.append(one[i-1] + one[i-2])
  return zero, one

t = int(input())
zero, one = fibo(40)
for _ in range(t):
  n = int(input())
  print('%d %d' %(zero[n], one[n]))
