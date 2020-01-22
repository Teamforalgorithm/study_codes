import sys
import math
n = int(sys.stdin.readline())
p = (n // 2) + 2
val = 0

def nCr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)
    
for k in range(p):
    val += nCr(n-k, k)

print(val)