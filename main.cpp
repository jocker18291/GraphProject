#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <fstream>
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
    std::uniform_int_distribution<> distWeight(1, 10);

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

void writeDot(const std::string &filename, int vertices, const std::vector<Edge> &edges, const std::vector<int>& distances) {
    std::ofstream out(filename);
    out << "graph G {\n";
    out << " node [shape=circle];\n";

    for(int i = 0; i < vertices; i++) {
        if(distances[i] == INT_MAX) {
            out << " " << i << " [label=\"" << i << "\\nINF\", style=filled, fillcolor=red];\n";
        } else {
            out << " " << i << " [label=\"" << i << "\\n" << distances[i] << "\", style=filled, fillcolor=lightblue];\n";
        }
    }

    for(auto &e : edges) {
        out << " " << e.u << " -- " << e.v << " [label=\"" << e.weight << "\"];\n";
    }
    out << "}\n";
    out.close();
}

int vertices = 10;
int density = 100;

void verifyGraphList() {
    graphList gl(vertices);
    auto edges = generateRandomEdges(vertices, density);
    for(const auto& edge : edges) {
        gl.addEdge(edge.u, edge.v, edge.weight);
    }
    auto b = gl.BellmanFord(0);
    auto d = gl.Dijkstra(0);

    bool ok = true;
    for(int i = 0; i < vertices; i++) {
        if(b[i] != d[i]) {
            ok = false;
        }
    }

    if(ok) {
        std::cout << "Perfect\n";
    } else {
        std::cout << "Not perfect...\n";
    }
}

void verifyGraphMatrix() {
    graphList gm(vertices);
    auto edges = generateRandomEdges(vertices, density);
    for(const auto& edge : edges) {
        gm.addEdge(edge.u, edge.v, edge.weight);
    }
    auto b = gm.BellmanFord(0);
    auto d = gm.Dijkstra(0);

    bool ok = true;
    for(int i = 0; i < vertices; i++) {
        if(b[i] != d[i]) {
            ok = false;
        }
    }

    if(ok) {
        std::cout << "Perfect\n";
    } else {
        std::cout << "Not perfect...\n";
    }
}

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
        gm.BellmanFord(0);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        totalTimeMatrix += elapsed.count();

        auto start2 = std::chrono::high_resolution_clock::now();
        gl.BellmanFord(0);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = end2 - start2;
        totalTimeList += elapsed2.count();
    }

    std::cout << "List," << vertices << ","<< totalTimeList / 100 << std::endl;
    std::cout << "Matrix," << vertices << "," << totalTimeMatrix / 100 << std::endl;
    
    int v = 6;
    int d = 50.0;
    auto edges = generateRandomEdges(v, d);
    graphMatrix gm(vertices);
        for(const auto& edge : edges) {
            gm.addEdge(edge.u, edge.v, edge.weight);
        }
    auto result = gm.Dijkstra(0);
    writeDot("graph.dot", v, edges, result);

    // verifyGraphList();
    // verifyGraphMatrix();
    return 0;
}