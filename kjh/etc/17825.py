import sys

arrDirec = [5, 10, 15]
arrSteps = [20, 7, 7, 7]
# arrDirec = [[1, 2, 3, 4, 5, -1,
#              7, 8, 9, 10, -2,
#              12, 13, 14, 15, -3,
#              17, 18, 19, 20],
#             [1, 2, 3, 4, 5, 6, 0],
#             [1, 2, 3, 4, 5, 0],
#             [1, 2, 3, 4, 5, 6, 0]]

arrScore = [[0, 2, 4, 6, 8, 10,
             12, 14, 16, 18, 20,
             22, 24, 26, 28, 30,
             32, 34, 36, 38, 40],
            [13, 16, 19, 25, 30, 35, 40],
            [22, 24, 25, 30, 35, 40],
            [28, 27, 26, 25, 30, 35, 40]
            ]

dice = list(map(int, sys.stdin.readline().split()))
max_score = 0

for count in range(4 ** 10):
    stepped = [False] * 4
    amount = [20] * 4
    horse = [0] * 4
    route = [0] * 4
    score = 0
    for i in range(10):
        j = count & 3
        count = count >> 2

        horse[j] += dice[i]

        amount[j] -= dice[i]
        if amount[j] <= 0:
            continue

        score += arrScore[route[j]][horse[j]]

        if horse[j] in arrDirec:
            route[j] = (horse[j] % 5) + 1
            amount[j] = arrSteps[j]
        # if route[j] == -1:
        #     continue

        # if amount[j] + dice[i] in amount:
        #     break
        # amount[j] += dice[i]
        # if len(arrDirec[route[j]]) <= amount[j]:
        #     route[j] = -1
        #     continue

        # score += arrScore[route[j]][amount[j]]

        # if arrDirec[route[j]][amount[j]] < 0:
        #     route[j] = -arrDirec[route[j]][amount[j]]

    max_score = max(max_score, score)

print(max_score)
