# WRONG
import sys

num = int(sys.stdin.readline())
schedules = []

for i in range(num):
    schedule = tuple(map(int, sys.stdin.readline().split()))
    schedules.appen
schedules.sort(key=lambda el: el[1])

time = 0
count = 0

while schedules:
    start, end = schedules.pop(0)
    if (start > time) and (end > time):
        count += 1
        time = end
print(count)
