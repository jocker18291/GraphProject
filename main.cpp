#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <chrono>
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

int vertices = 10;
int density = 25;

int main() {
    double totalTimeList = 0.0;
    double totalTimeMatrix = 0.0;

    for(int i = 0; i < 100; ++i) {
        auto edges = generateRandomEdges(vertices, density);

        graphMatrix gm(vertices);
        for(const auto& edge : edges) {
            gm.addEdge(edge.u, edge.v, edge.weight);
        }

        graphList gl(vertices);
        for(const auto& edge : edges) {
            gl.addEdge(edge.u, edge.v, edge.weight);
        }

        auto start = std::chrono::high_resolution_clock::now();
        gm.BFS(0);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        totalTimeMatrix += elapsed.count();

        auto start2 = std::chrono::high_resolution_clock::now();
        gl.BFS(0);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = end2 - start2;
        totalTimeList += elapsed2.count();
    }
    
    return 0;
}