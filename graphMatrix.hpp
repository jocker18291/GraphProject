#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP
#include <vector>

class graphMatrix {
private:
    int vertices;
    std::vector<std::vector<int>> matrix;
public:
    graphMatrix(int v);
    void addEdge(int src, int dest, int weight = 1);
    void printMatrix() const;
    void BFS(int start) const;
};

#endif