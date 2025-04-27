#include <iostream>
#include <vector>
#include <list>

class graphList {
private:
    int vertices;
    std::vector<std::list<std::pair<int, int>>> adjList;
};