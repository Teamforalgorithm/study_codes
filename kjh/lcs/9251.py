import sys

A = str(sys.stdin.readline().strip())
B = str(sys.stdin.readline().strip())
count = 0
keyB = 0

for valA in A:
    for (key, valB) in enumerate(B[keyB:]):
        if valA == valB:
            count += 1
            keyB = keyB + key + 1
            # print(valA, keyB)
            break

print(count)
