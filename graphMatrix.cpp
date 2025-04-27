#include <iostream>
#include <queue>
#include <limits>
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

void graphMatrix::BFS(int start) const {
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    std::cout << "BFS starting from vertex: " << start << std::endl;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        for(int neighbor = 0; neighbor < vertices; neighbor++) {
            if(matrix[current][neighbor] != 0 && !visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        std::cout << std::endl;
    }
}

void graphMatrix::Dijkstra(int start) const {
    std::vector<int> distance(vertices, std::numeric_limits<int>::max());
    distance[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        for(int i = 0; i < vertices; ++i) {
            if(matrix[currentVertex][i] != 0) {
                int weight = matrix[currentVertex][i];

                if(distance[i] > currentDistance + weight) {
                    distance[i] = currentDistance + weight;
                    pq.push({distance[i], i});
                }
            }
        }
    }
    std::cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < vertices; ++i) {
            if (distance[i] == std::numeric_limits<int>::max()) {
                std::cout << "Vertex " << i << ": unreachable\n";
            } else {
                std::cout << "Vertex " << i << ": " << distance[i] << "\n";
            }
        }
}
