#include <iostream>
#include <vector>
#include <list>
#include "graphList.hpp"

graphList::graphList(int v) {
    vertices = v;
    adjList.resize(vertices);
}

void graphList::addEdge(int src, int dest, int weight = 1) {
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
