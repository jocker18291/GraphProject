#include <iostream>
#include "graphList.hpp"
#include "graphMatrix.hpp"

int main() {
    graphMatrix gm(5);
    gm.addEdge(0, 1, 2);
    gm.addEdge(0, 4);
    gm.printMatrix();

    graphList gl(5);
    gl.addEdge(0, 1, 2);
    gl.addEdge(0, 4);
    gl.printList();
    return 0;
}