#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <queue>
#include "graphList.hpp"

graphList::graphList(int v) {
    vertices = v;
    adjList.resize(vertices);
}

void graphList::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight});
}

void graphList::printList() const {
    for(int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        for(const auto& neighbor : adjList[i]) {
            std::cout << "(" <<neighbor.first << ", " << neighbor.second << ")";
        }
        std::cout << std::endl;
    }
}

void graphList::BFS(int start) const {
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    //std::cout << "BFS starting from vertex " << start << ": ";

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        //std::cout << current << " ";
        for(const auto& neighbor : adjList[current]){
            int neighborVertex = neighbor.first;
            if(!visited[neighborVertex]) {
                visited[neighborVertex] = true;
                q.push(neighborVertex);
            }
        }
    }
    //std::cout << std::endl;
}

std::vector<int> graphList::Dijkstra(int start) const {
    std::vector<int> distance(vertices, std::numeric_limits<int>::max());
    distance[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    pq.push({0, start});

    while(!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[currentVertex]) {
            int neighborVertex = neighbor.first;
            int weight = neighbor.second;

            if(distance[neighborVertex] > currentDistance + weight) {
                distance[neighborVertex] = currentDistance + weight;
                pq.push({distance[neighborVertex], neighborVertex});
            }
        }
    }

    return distance;

    // std::cout << "Shortest distances from vertex " << start << ":\n";
    // for(int i = 0; i < vertices; ++i){
    //     if(distance[i] == std::numeric_limits<int>::max()) {
    //         std::cout << "Vertex " << i << ": unreachable\n";
    //     } else {
    //         std::cout << "Vertex " << i << ": " << distance[i] << "\n";
    //     }
    // }
}

std::vector<int> graphList::BellmanFord(int start) const {
    std::vector<int> distance(vertices, std::numeric_limits<int>::max());
    distance[start] = 0;

    for(int i = 0; i < vertices - 1; ++i) {
        for(int u = 0; u < vertices; ++u) {
            for(const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if(distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int u = 0; u < vertices; ++u) {
        for(const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                hasNegativeCycle = true;
            }
        }
    }
    return distance;

    // if (hasNegativeCycle) {
    //     std::cout << "Graph contains a negative weight cycle!\n";
    // } else {
    //     std::cout << "Shortest distances from vertex " << start << ":\n";
    //         for (int i = 0; i < vertices; ++i) {
    //             if (distance[i] == std::numeric_limits<int>::max()) {
    //                 std::cout << "Vertex " << i << ": unreachable\n";
    //             } else {
    //                 std::cout << "Vertex " << i << ": " << distance[i] << "\n";
    //             }
    //         }
    // }
}
