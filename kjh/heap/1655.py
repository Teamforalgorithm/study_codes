import sys
import heapq

N = int(sys.stdin.readline())
heap = []
# temp = []
count = 1
i = 0
while i < N:
    heapq.heappush(heap, int(sys.stdin.readline()))
    print(heapq.nsmallest(int(count), heap)[-1])
    count += 0.5
    i += 1


# for i in range(N):
#     heapq.heappush(heap, int(sys.stdin.readline()))
#     print(heapq.nsmallest(count, heap)[-1])

#     if (i)
#     heapq.heappush(heap, int(sys.stdin.readline()))
#     print(heapq.nsmallest(count, heap)[-1])
#     count += 1

    # print("count: ", count)
    # print(heapq.nsmallest(((len(heap) - 1) // 2 + 1), heap)[-1])
    
    # half = (len(heap) - 1) // 2 + 1
    # for j in range(half):
    #     temp.append(heapq.heappop(heap))
    # print(temp[-1])

    # # for j in temp:
    # while temp:
    #     heapq.heappush(heap, temp.pop())
    
    # # print(heap)
