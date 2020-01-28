import sys
import math

A, B, V = map(int, sys.stdin.readline().split())

print(math.ceil((V - B - 1) / (A - B) + 1))
