import sys


def input(): return sys.stdin.readline().strip()


n = int(input())
arr = list(map(int, input().split()))
m = int(input())

# 가능한 경우에는 모든 요청을 그대로 배정
# 아니면 특정한 정수 상한액을 계산해서 그 이상의 요청액은 모두 상한액으로 배정
# 상한액 이하의 요청은 그대로 배정


def MaxNum(num):
    ret = 0
    for i in arr:
        if i > num:
            ret += num
        else:
            ret += i
    return ret


def BSearch(target):
    start, end = 1, m
    ans = 0
    while(start <= end):
        mid = (start + end) // 2
        tmp = MaxNum(mid)

        if tmp <= target:
            if ans < mid:
                ans = mid
            start = mid + 1
        if tmp > target:
            end = mid - 1

    return ans


acc = sum(arr)
if acc <= m:
    print(max(arr))
else:
    print(BSearch(m))
