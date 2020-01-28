import sys
A, B = map(int, sys.stdin.readline().split())
def computeGCD(x, y): 
   while(y): 
       x, y = y, x % y 
   return x 
  
GCD = computeGCD(A, B)
print(GCD)
print(A * B // GCD)