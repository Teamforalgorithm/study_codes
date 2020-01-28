import sys
import heapq

num = int(sys.stdin.readline())
schedules = []

for i in range(num):
    schedule = tuple(map(int, sys.stdin.readline().split()))
    heapq.heappush(schedules, (schedule[1], schedule[0]))

schedules.sort(key=lambda el: el[1])

print(schedules)

time = 0
count = 0

while schedules:
    end, start = heapq.heappop(schedules)
    if (start >= time) and (end >= time):
        count += 1
        time = end
print(count)
