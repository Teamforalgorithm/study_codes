# Alogorithm Review

- Written in 2019. 01. 26.
- Author: Kim Jihyeong (kimjihyeong100@gmail.com)

## 개요

- BOJ 기초 개념 정리를 요약합니다.

## 그래프와 그래프의 표현방법

그래프는 다음 두가지를 포함하는 자료구조형이다.

- 노드라고 불리는 유한한 정점이 존재
- 엣지라고 불리는 $(u, v)$ 꼴의 유한한 순서쌍이 존재.

방향성이 있는 그래프에서는 $(u, v)$ 엣지 와 $(v, u)$ 엣지가 다르다. 또한 엣지는 weight/value/cost 들으로 불리는 가중치가 포함될 수 있다.

그래프는 현실 상황 많은 곳에서 적용할 수 있다. 그래프는 네트워크에서 많이 쓰이는데, 네트워크는 도시 경로나 전화망, 전자회로 같은 것을 포함한다.

다음은 5개의 정점을 포함하는 무방향성 그래프를 표현한 것이다.

![5 Vertices Graph](https://media.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png)

- 다음과 같은 그래프를 표현하는데 주로 두 가지의 방법을 이용한다.

  1. Adjacency Matrix
  1. Adjacency List

Incidence Matrix, Incidence List과 와 같은 표현방법도 있지만 이런 것들은 특수한 상황에서 이용된다. 이러한 방법들은 수행할 작업의 유형가 사용 편의성에 전적으로 의존한다.

### Adjacency Matrix

Adjacency Matrix는 V x V 크기의 2차원의 배열이다. V는 정점의 개수를 의미하며, 2차원 배열을 `adj[][]`로 정의하면 `adj[i][j] = 1`은 정점 `i`에서 정점 `j`까지 이어지는 간선이 있다는 것을 의미한다. 무방향성 그래프의 Adjacency Matrix는 항상 주축을 기준으로 대칭적이다. Adjacency Matrix는 가중치가 있는 그래프도 표현할 수 있는데, 정점 `i`에서 정점 `j`까지 가는 간선이 있는데, 그 간선의 가중치가 `w`라면 `adj[i][j] = w`라고 표현할 수 있다.

상기 그래프를 Adjacency Matrix로 표현하면 다음과 같다.

![Adjacency Matrix](https://media.geeksforgeeks.org/wp-content/uploads/adjacencymatrix.png)

- 장점: 적용하기 쉽고 따라하기도 쉽다. 간선 하나를 지우는데 $O(1)$의 시간복잡도를 가진다. 정점 `u`에서 정점 `v`로 가는 간선을 생성하는 쿼리는 효율적이며 이 역시 $O(1)$의 시간복잡도를 가진다.
- 단점: $O(V^2)$의 공간복잡도를 차지한다. 만약 그래프가 sparse 하더라도(간선의 개수가 적더라도) 같은 공간복잡도를 가진다. 정점 하나를 추가하면 $O(V^2)$의 시간을 소요한다. [다음 링크](https://ide.geeksforgeeks.org/9je5j6jJ13)를 통해 adjacency matrix의 파이썬 적용 코드를 확인하기 바란다.

### Adjacency List

- 리스트들의 배열을 사용한다. 배열의 크기는 정점 개수와 같다. 배열을 `array[]`라 하면, `array[i]`의 첫주소는 `i`번째 정점과 인접한 정점의 리스트를 표현한다. 이 표현 방법은 가중치 그래프 역시 표현 가능하다. 간선의 가중치는 한 쌍의 리스트로 표현된다. 상기 그래프를 adjacency list로 표현하면 다음과 같다.

![Adjacency List](https://media.geeksforgeeks.org/wp-content/uploads/listadjacency.png)

#### Codes

##### C++

```c++
// A simple representation of graph using STL
#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

// Driver code
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
```

##### C

```c
// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph =
        (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of
    // array will be V
    graph->array =
      (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
```

##### Python3

```python
"""
A Python program to demonstrate the adjacency
list representation of the graph
"""

# A class to represent the adjacency list of the node
class AdjNode:
    def __init__(self, data):
        self.vertex = data
        self.next = None


# A class to represent a graph. A graph
# is the list of the adjacency lists.
# Size of the array will be the no. of the
# vertices "V"
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [None] * self.V

    # Function to add an edge in an undirected graph
    def add_edge(self, src, dest):
        # Adding the node to the source node
        node = AdjNode(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        # Adding the source node to the destination as
        # it is the undirected graph
        node = AdjNode(src)
        node.next = self.graph[dest]
        self.graph[dest] = node

    # Function to print the graph
    def print_graph(self):
        for i in range(self.V):
            print("Adjacency list of vertex {}\n head".format(i), end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print(" \n")


# Driver program to the above graph class
if __name__ == "__main__":
    V = 5
    graph = Graph(V)
    graph.add_edge(0, 1)
    graph.add_edge(0, 4)
    graph.add_edge(1, 2)
    graph.add_edge(1, 3)
    graph.add_edge(1, 4)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)

    graph.print_graph()

# This code is contributed by Kanav Malhotra
```

- Notes: C++에서 Adjacency list를 표현하기 위해 linked list 대신 dynamic arrays를 이용하였는데, 이는 캐시 친화적인 이점을 누리기 위해서 이렇게 표현하였다.

#### 결과

```text
 Adjacency list of vertex 0
 head -> 1-> 4

 Adjacency list of vertex 1
 head -> 0-> 2-> 3-> 4

 Adjacency list of vertex 2
 head -> 1-> 3

 Adjacency list of vertex 3
 head -> 1-> 2-> 4

 Adjacency list of vertex 4
 head -> 0-> 1-> 3
```

- 장점: $O(|V| + |E|)$의 공간복잡도로 절약할 수 있다. 최악의 경우 $C(V, 2)$개의 간선이 그래프에 있을 수 있는데, $O(V^2)$의 공간을 차지할 수 있다. 정점을 추가하기 편하다.

- 단점: 정점 `u`에서 정점 `v`로 가는 간선을 생성하는 쿼리는 효율적이지 않으며, $O(V)$의 복잡도로 이루어진다.

> References: [Graph and its representations](https://www.geeksforgeeks.org/graph-and-its-representations/)

## 깊이 우선 탐색과 너비 우선 탐색

![Network Graph](https://camo.githubusercontent.com/3b2db70a81777815bb8cf5474278129457a28c18/687474703a2f2f6d617468776f726c642e776f6c6672616d2e636f6d2f696d616765732f6570732d6769662f47726170684e6f64657345646765735f313030302e676966)

- 그래프에는 정점(node)과 간선(edge)로 이루어져 있는데, 간선을 통해서 모든 정점을 방문하는 것을 '그래프를 탐색한다'라고 한다.
- 그래프 탐색 알고리즘에는 깊이 우선 탐색(Depth First Search)과 너비 우선 탐색(Breadth First Search)로 나뉘어지는데, 각각의 알고리즘에 대해 정의해보자.

![DFS vs BFS](https://t1.daumcdn.net/cfile/tistory/997183445C7625B921)

### 깊이 우선 탐색 (DFS)

![DFS](https://t1.daumcdn.net/cfile/tistory/99D8C0365C762AC528)

- 그래프에서 노드의 자식들을 우선적으로 탐색하는 방법이다. 그래프에서 한 정점을 루트 노드로 잡으면 항상 트리를 생성할 수 있는데, 루트 노드를 기준으로 지나가는 정점의 수 또는 간선의 수에 따라 부모 - 자식 관계를 정의할 수 있을 것이다. 이 떄 자식의 노드를 우선적으로 탐색한다는 의미이며, 최대한 깊숙히 탐색한 후 다시 돌아가 다른 부모 노드를 탐색하는 방법이다. 스택 자료구조형으로 이를 구현할 수 있다.

### 너비 우선 탐색 (BFS)

![BFS](https://t1.daumcdn.net/cfile/tistory/9955D24A5C76320A36)

- 그래프에서 루트 노드로부터 인접한 정점, 즉 자식부터가 아닌 같은 레벨의 부모 노드부터 우선 탐색하는 방법이다. 출발 노드에서 목표 노드까지의 최단 길이 경로를 보장한다. 큐 자료구조형으로 이를 구현할 수 있다.

## 백트래킹 (Back Tracking)

- 백트래킹은 '퇴각 검색'의 의미로서, 한정 조건을 가진 문제를 풀려는 전략이다. 백트래킹이란 용어는 1950년대 미국 수학자 D.H Lemmer가 지었다.
- 문제가 한정 조건을 가진 경우 원소의 순서는 해결 방법과 무관하다. 이런 문제는 변수 집합으로 이루어지는데, 한정 조건을 구성하려면 각각의 변수들은 값이 있어야 한다. 이 떄 백트래킹은 모든 조합을 시도해서 문제의 해를 찾는다.
- 이것이 장점이 될 수 있는 이유는 백트래킹 구현 방법들이 많은 부분 조합들을 배제하기 때문이다. 어떤 노드의 유망성을 점검하고, 해당 노드가 유망하지 않으면 그 노드의 부모 노드로 되돌아간 후 다른 자손 노드를 검색한다.결국 풀이 시간이 단축된다.
- 백트래킹의 대표적인 예제 `4-Queens Problem`을 통해 백트래킹을 이해하자.

![4-Queens Problem](https://t1.daumcdn.net/cfile/tistory/275E284456EFDAB002)

> References: [[알고리즘] 되추적(Backtracking)을 알아보자.](https://idea-sketch.tistory.com/29)
