#include <iostream>
#include <vector>
#include <list>

class graphList {
private:
    int vertices;
    std::vector<std::list<std::pair<int, int>>> adjList;
public:
    graphList(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
    }

    void printList() const {
        for(int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for(const auto& neighbor : adjList[i]) {
                std::cout << "(" <<neighbor.first << ", " << neighbor.second << ")";
            }
            std::cout << std::endl;
        }
    }
};