import sys
import collections
n,m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
num, count = map(list, zip(*list(collections.Counter(arr).items())))
a = [0]*9
def solve(c):
    if c==m:
        print(' '.join(map(str, [i for i in a if i != 0])))
        return
    else:
        for i in range(len(count)):
            if count[i]:
                count[i]-=1
                a.append(num[i])
                solve(c+1)
                a.pop()
                count[i]+=1
solve(0)