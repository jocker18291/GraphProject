#ifndef GRAPH_LIST_HPP
#define GRAPH_LIST_HPP
#include <vector>
#include <list>

class graphList {
private:
    int vertices;
    std::vector<std::list<std::pair<int, int>>> adjList;
public:
    graphList(int v);
    void addEdge(int src, int dest, int weight = 1);
    void printList() const;
    void BFS(int start) const;
    void Dijkstra(int start) const;
};

#endif