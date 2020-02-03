import sys

N = int(sys.stdin.readline())
tower = [[i for i in range(N, 0, -1)], [], []]
order = []

def move(_from, _to, _temp, num):
    if num == 1:
        tower[_to].append(tower[_from].pop())
        order.append((_from, _to))
        return
    else:
        move(_from, _temp, _to, num - 1)
        tower[_to].append(tower[_from].pop())
        order.append((_from, _to))
        move(_temp, _to, _from, num - 1)

move(0, 2, 1, N)
print(len(order))
[print(i+1, j+1, sep=' ') for i, j in order]