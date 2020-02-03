import sys

N = int(sys.stdin.readline())
mat = []

for _ in range(N):
    mat.append(sys.stdin.readline().strip())

def divideBlock(pos_x, pos_y, size):
    size //= 2
    print('(', end='')
    checkBlock(pos_x, pos_y, size)
    checkBlock(pos_x + size, pos_y, size)
    checkBlock(pos_x, pos_y + size, size)
    checkBlock(pos_x + size, pos_y + size, size)
    print(')', end='')

def checkBlock(pos_x, pos_y, size):
    val = ''
    for i in mat[pos_y:pos_y+size]:
        row = i[pos_x:pos_x+size]
        if val == '':
            if (row == '1'*size) or (row == '0'*size):
                val = row
            else:
                divideBlock(pos_x, pos_y, size)
                break
        else:
            if row != val:
                divideBlock(pos_x, pos_y, size)
                val = ''
                break

    if val:
        print(val[0], end='')


checkBlock(0, 0, N)
print()