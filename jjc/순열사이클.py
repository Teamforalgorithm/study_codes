import sys
def dfs(x,check,path):
    if check[x]:
        return
    check[x]=1

    dfs(path[x]-1,check,path)
 
sys.setrecursionlimit(2000)
for i in range(int(input())):
    n=int(input())
    path=list(map(int,input().split()))
    check=[0]*n
    ans = 0
    for j in range(n):
        if check[j] ==0:
            dfs(j,check,path)
            ans+=1
    print(ans)