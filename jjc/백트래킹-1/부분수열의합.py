import sys
input=sys.stdin.readline

def make_comb(arr, comb, s):
    cnt = 0
    for front in arr:
        for end in list(comb):
            comb.append(front + end)
            print(comb)
            if comb[-1] == s:
                cnt += 1
    return cnt

if __name__ == "__main__":
    n, s = map(int, input().split())
    comb = [0]
    cnt = make_comb([*map(int, input().split())], comb, s)
    print(cnt)