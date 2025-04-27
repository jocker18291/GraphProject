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
};