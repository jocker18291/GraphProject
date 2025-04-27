#include <iostream>
#include <vector>
#include <set>
#include <random>
#include "graphList.hpp"
#include "graphMatrix.hpp"

struct Edge {
    int u, v, weight;
};

std::vector<Edge> generateRandomEdges(int vertices, double density) {
    int maxEdges = vertices * (vertices - 1) / 2;
    int targetEdges = static_cast<int>(maxEdges * (density / 100.0));

    std::set<std::pair<int, int>> existingEdges;
    std::vector<Edge> edges;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distVertex(0, vertices - 1);
    std::uniform_int_distribution<> distWeight(0, 10);

    while(edges.size() < targetEdges) {
        int u = distVertex(gen);
        int v = distVertex(gen);

        if (u == v) continue;

        if (u > v) std::swap(u, v);

        if(existingEdges.find({u, v}) == existingEdges.end()) {
            int weight = distWeight(gen);
            edges.push_back({u, v, weight});
            existingEdges.insert({u, v});
        }
    }

    return edges;
}

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