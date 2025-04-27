#include <iostream>
#include <vector>
#include "graphMatrix.hpp"

graphMatrix::graphMatrix(int v) {
    vertices = v;
    matrix.resize(vertices, std::vector<int>(vertices, 0)); //vertices x vertices matrix filled with 0s
}

void graphMatrix::addEdge(int src, int dest, int weight) {
    matrix[src][dest] = weight;
    matrix[dest][src] = weight; //for non-oriented graph
}

void graphMatrix::printMatrix() const {
    for(const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
