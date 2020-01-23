# ERROR
import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
count = N
val = 0

eff = [(arr[i] / (i + 1)) for i in range(N)]
print(eff)

while count > 0:
    selected = eff.index(max(eff[:count]))
    count -= selected + 1
    val += arr[selected]

print(val)
