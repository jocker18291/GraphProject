#include <iostream>
#include <vector>

class graphMatrix {
private:
    int vertices;
    std::vector<std::vector<int>> matrix;
public:
    graphMatrix(int v) {
        vertices = v;
        matrix.resize(vertices, std::vector<int>(vertices, 0));
    }
};