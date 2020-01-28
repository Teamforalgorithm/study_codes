import sys
num = int(sys.stdin.readline())

result = []

arrX = [0] * num
arrA = [0] * (num - 1)
arrB = [0] * (num - 1)


for x in range(num):
    arrX[x] = 1
    result.push(search(arrA, arrB, arrX, 0)

def search(arrA, arrB, arrX, y):
    y += 1
    if y > num:
        return 1

    for x, val in enumerate(arrX):
        if not val and not arrA[y - x - (num // 2)] and not arrB[y + x - (num // 2)]:
            arrX[x]=1
            arrA[y - x - (num // 2)]=1
            arrB[y + x - (num // 2)]=1
            search(arrA, arrB, arrX, y)



    arrA.push()
