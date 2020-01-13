import sys
input = sys.stdin.readline

n, m = map(int, input().split())

def get_primes(n, m):
  is_primes = [True]*m
  
  for i in range(2, m, 1):
    if is_primes[i]:
      for j in range(i+i, m, i):
        is_primes[j] = False
  
  for i in range(n, m, 1):
    if is_primes[i]:
      print(i)

def is_prime(num):
  if num<=1:
    return False
  i = 2
  while i*i <= num:
    if num % i == 0:
      return False

    i+=1
  return True

# get_primes(n, m)

for i in range(n, m+1):
  if is_prime(i):
    print(i)