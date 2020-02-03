import sys

N, M = map(int, sys.stdin.readline().split())
edge = []

class Node:
    num = ""
    edges = []

    def __init__(self, num):
        self.num = num
    
    def addEdge(self, num):
        self.edges.append(num)


for _ in range(M):
    edge.append(tuple(map(int, sys.stdin.readline().split())))
