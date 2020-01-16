import sys
from itertools import *

n,m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
c = sorted(set(combinations(arr, m)))
for i in c:
    print(*i)