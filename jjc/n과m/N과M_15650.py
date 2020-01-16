import sys

n,m = map(int, sys.stdin.readline().split())
check = [False]*n
a = [0]*9

def solve(start, idx):
    print("start: "+ str(start) + " idx: "+str(idx))
    if idx==m:
        print(' '.join(map(str, [i for i in a if i!=0])))
        print("pass")
        return
    else:
        print("pass2")
        for i in range(start, n+1):
            print("입력 값"+ " idx: "+ str(idx) + " i: "+str(i))
            print(a)
            print()
            a[idx] = i
            solve(i+1, idx+1)

solve(1, 0)