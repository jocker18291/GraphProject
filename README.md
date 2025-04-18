# GraphProject
**Project Description**

The goal of this project is to implement selected graph algorithms and analyze their performance depending on the graph representation and size.

**Implemented Algorithms**
* **Dijkstra's Algorithm** - for finding the shortest paths in graphs with non-negative edge weights.
* **Bellman-Ford Algorithm** - for graphs with negative edge weights (detects negative cycles).
* **Depth-First Search (DFS)** - graph traversal algorithm.

**Experimental Evaluation**

All algorithms are tested using graphs generated randomly with different configurations. Each graph is represented in two forms:
* **Adjacency list**
* **Adjacency matrix**

**Parameters**
* **Number of vertices**: 10, 50, 100, 200, 500
* **Graph density**: 25%, 50%, 75%, 100% (complete graph)

Each combination of:
* algorithm,
* graph representation,
* number of vertices,
* and density
is tested using **randomly 100 generated instances.**

Execution times are measured and **averaged** to ensure statistically reliable performance comparisons.
