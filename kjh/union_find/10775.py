# WRONG
import sys
from collections import deque

G = int(sys.stdin.readline())
P = int(sys.stdin.readline())
gates = list(range(G))
count = 0

p = 0
hasCrashed = False
while p < P:
    print(gates)
    num = int(sys.stdin.readline()) - 1
    if not hasCrashed:
        if gates[num] > 0:
            gates[num] -= 1
            count += 1
        else:
            hasCrashed = True
    p += 1

print(count)
