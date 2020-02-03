import sys
test = int(sys.stdin.readline())
for _ in range(test):
    N = int(sys.stdin.readline())
    net = {}
    counts = {}
    last = 0
    for __ in range(N):
        a, b = map(str, sys.stdin.readline().split())

        if a in net:
            if b in net:
                if net[a] == net[b]:
                    print(counts[net[a]])
                    continue
                else:
                    counts[net[a]] += counts[net[b]]
                    counts.pop(net[b])
            else:
                counts[net[a]] += 1
            net[b] = net[a]
        elif b in net:
            counts[net[b]] += 1
            net[a] = net[b]
        else:
            net[a] = net[b] = last
            counts[last] = 2
            last += 1

        print(counts[net[a]])

        # if a in net:
        # else:
        #     print(counts[net[b]])
