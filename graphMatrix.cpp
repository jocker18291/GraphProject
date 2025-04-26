#include <iostream>
#include <vector>

class graphMatrix {
private:
    int vertices;
    std::vector<std::vector<int>> matrix;
public:
    graphMatrix(int v) {
        vertices = v;
        matrix.resize(vertices, std::vector<int>(vertices, 0)); //vertices x vertices matrix filled with 0s
    }

    void addEdge(int src, int dest, int weight = 1) {
        matrix[src][dest] = weight;
        matrix[dest][src] = weight; //for non-oriented graph
    }

    void printMatrix() const {
        for(const auto& row : matrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};