# A union by rank and path compression based 
# program to detect cycle in a graph 
from collections import defaultdict 
# defaultdict는 딕셔너리와 비슷하지만 key값이 없을 경우 미리 지정해놓은 초기값을 반환하는 딕셔너리

# a structure to represent a graph 
class Graph: 
	def __init__(self, num_of_v): 
		self.num_of_v = num_of_v 
		self.edges = defaultdict(list) 
		
	# graph is represented as an 
	# array of edges 
	def add_edge(self, u, v): 
		self.edges[u].append(v) 


class Subset: 
  # MakeSet
	def __init__(self, parent, rank): 
		self.parent = parent 
		self.rank = rank 

# A utility function to find set of an element 
# node(uses path compression technique) 
def find(subsets, node): 
	if subsets[node].parent != node: 
		subsets[node].parent = find(subsets, subsets[node].parent) 
	return subsets[node].parent 

# A function that does union of two sets 
# of u and v(uses union by rank) 
def union(subsets, u, v): 
	# Attach smaller rank tree under root 
	# of high rank tree(Union by Rank) 
	if subsets[u].rank > subsets[v].rank: 
		subsets[v].parent = u 
	elif subsets[v].rank > subsets[u].rank: 
		subsets[u].parent = v 
		
	# If ranks are same, then make one as 
	# root and increment its rank by one 
	else: 
		subsets[v].parent = u 
		subsets[u].rank += 1

# The main function to check whether a given 
# graph contains cycle or not 
def isCycle(graph): 
	
	# Allocate memory for creating sets 
	subsets = [] 

	for u in range(graph.num_of_v): 
		subsets.append(Subset(u, 0)) 

	# Iterate through all edges of graph, 
	# find sets of both vertices of every 
	# edge, if sets are same, then there 
	# is cycle in graph. 
	for u in graph.edges: 
		u_rep = find(subsets, u) 

		for v in graph.edges[u]: 
			v_rep = find(subsets, v) 

			if u_rep == v_rep: 
				return True
			else: 
				union(subsets, u_rep, v_rep) 

# Driver Code 
g = Graph(3) 

# add edge 0-1 
g.add_edge(0, 1) 

# add edge 1-2 
g.add_edge(1, 2) 

# add edge 0-2 
g.add_edge(0, 2) 

if isCycle(g): 
	print('Graph contains cycle') 
else: 
	print('Graph does not contain cycle') 
