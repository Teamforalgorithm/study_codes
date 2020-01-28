def binary_search():
    first, last = 0, max(arr)
    check = 0
    while first <= last or check > x:
        check = 0
        mid = (first + last) // 2
        for i in arr:
            if i < mid:
                check += i
            else:
                check += mid
        if check <= x:
            first = mid + 1
        else:
            last = mid - 1
    print(mid)


n = int(input())
arr = list(map(int, input().split()))
x = int(input())
binary_search()
