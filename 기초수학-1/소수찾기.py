import sys
input = sys.stdin.readline

n = int(input())
ans = 0

def is_prime1(num):
  # 가장 심플하게 생각해본거
  if num>1:
    if num == 2 or num == 3 or num ==5:
      return True
    if num%2!=0 and num%3!=0 and num%5!=0: 
      return True
  else:
    return False

def is_prime(arr):
  # 이건 에라토스 테네스의 체를 안쓰고 푼거
  global ans
  for i in arr:
    cnt = 0
    for j in range(1, i+1):
      if i % j == 0:
        cnt += 1
    if cnt == 2:
      # 소수는 1과 자기자신으로만 나눠지니까 cnt가 2여야 소수
      ans+=1
  return ans

def get_primes(n):
  # 구하고자 하는 만큼 True 갖는 리스트 생성
  is_primes = [True] * n
  # n의 최대 약수가 sqrt(n) 이하이므로 계산한 후, 소수점이 있을 경우 올림으로 최대 반복 횟수 계산
  max_length = math.ceil(math.sqrt(n))
  #ceil은 반올림해줌

  for i in range(2, max_length):
    # True일 경우, 소수
    if is_primes[i]:
      # i이후 i의 배수를 지운다.
      for j in range(i+i, n, i):
        is_primes[j] = False
  # 리스트의 True로 남아 있는 소수 추출
  return [i for i in range(2, n) if is_primes[i]]

arr = list(map(int, input().split()))
result = is_prime(arr)

print(result)
